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

void loop(shared<Thread> thread, shared_buffer bytecode) {
    shared<Frame> frame = thread->popFrame();
    auto reader = std::make_shared<BytecodeReader>();
    try {
        while (true) {
            auto pc = frame->nextPc;
            thread->setPc(pc);
            // decode
            reader->reset(bytecode, pc);
            auto opcode = reader->readUint8();
            LOG_INFO("opcode: 0x%x", (uint)opcode);
            auto inst = instructions::newInstruction(opcode);
            inst->fetchOperands(reader);
            LOG_INFO("pc: %2d, inst: %s", pc, inst->toString());
            if (opcode == 0xb2) {
                LOG_INFO("localVars: %1%", frame->localVars->toString());
            }
            frame->setNextPc(reader->pc);
            // execute
            inst->execute(frame);
        }
    } catch (...) {
        LOG_INFO("localVars: %1%", frame->localVars->toString());
    }

}

void Interpreter::interpret(std::shared_ptr<heap::Method> method) {
//    auto thread = thread::newThread();
//    auto codeAttr = memberInfo->getCodeAttribute();
//    auto maxLocals = codeAttr->maxLocals;
//    auto maxStack = codeAttr->maxStack;
//    auto bytecode = codeAttr->code;
    LOG_INFO("interpreting...");
    auto thread = thread::newThread();
    auto frame = thread->newFrame(method);
    thread->pushFrame(frame);
    loop(thread, method->code);
}
