//
// Created by strike on 4/10/23.
//

#include "interpreter.h"
#include "../rtda/Frame.h"
#include "../rtda/Thread.h"
#include "../instructions/factory.h"
#include <boost/type_index.hpp>
#include <memory>
#include "../log/log.h"
#include "../rtda/heap/string_pool.h"

void logFrames(shared<Thread> thread) {
    while (!thread->isStackEmpty()) {
        auto frame = thread->popFrame();
        auto method = frame->method;
        auto className = method->klass->name;
        LOG_INFO(">> pc: %1% %2%.%3%%4%  ", frame->nextPc, *className, *method->name, *method->descriptor);
    }
}

void logInstruction(shared<Frame> frame, shared<Instruction> inst) {
    auto method = frame->method;
    auto className = method->klass->name;
    auto methodName = method->name;
    auto pc = frame->thread->pc;
    LOG_INFO("%1%.%2%() # %3% %4% %5%", *className, *methodName, pc, inst->toString(), typeid(*inst).name())
}

void loop(shared<Thread> thread, bool logInst) {
    shared<Frame> frame = thread->currentFrame();
    auto reader = std::make_shared<BytecodeReader>();
    try {
        while (true) {
            frame = thread->currentFrame();
            auto pc = frame->nextPc;
            thread->setPc(pc);
            // decode
            reader->reset(frame->method->code, pc);
            auto opcode = reader->readUint8();
//            LOG_INFO("opcode: 0x%x", (uint)opcode);
            auto inst = instructions::newInstruction(opcode);
            inst->fetchOperands(reader);
//            LOG_INFO("pc: %2d, inst: %s", pc, inst->toString());
            frame->setNextPc(reader->pc);
            if (logInst) {
                logInstruction(frame, inst);
            }
            // execute
            inst->execute(frame);
            if (thread->isStackEmpty()) {
                break;
            }
        }
    } catch (...) {
        logFrames(frame->thread);
    }

}

heap::Object* createArgsArray(shared<heap::ClassLoader> loader, sv<string> args) {
    auto stringClass = loader->loadClass(make_shared<string>("java/lang/String"));
    auto argsArr = stringClass->arrayClass()->newArray(args->size());
    auto jArgs = dynamic_cast<heap::ArrayObject<heap::Object*>*>(argsArr)->getData();
    for (int i = 0; i < args->size(); i++) {
        jArgs[i] = heap::JString(loader, make_shared<string>(args->at(i)));
    }
    return argsArr;
}

void Interpreter::interpret(std::shared_ptr<heap::Method> method, bool logInst, sv<string> args) {
//    auto thread = thread::newThread();
//    auto codeAttr = memberInfo->getCodeAttribute();
//    auto maxLocals = codeAttr->maxLocals;
//    auto maxStack = codeAttr->maxStack;
//    auto bytecode = codeAttr->code;
    LOG_INFO("interpreting...");
    auto thread = thread::newThread();
    auto frame = thread->newFrame(method);
    thread->pushFrame(frame);
    LOG_INFO("interpret");
    auto jArgs = createArgsArray(method->klass->loader, args);
    LOG_INFO("interpret");
    frame->localVars->setRef(0, jArgs);
    loop(thread, logInst);
}
