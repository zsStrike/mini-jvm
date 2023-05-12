//
// Created by strike on 5/12/23.
//

#include "invokeinterface.h"
#include "../base/method_invoke_logic.h"
#include "../../rtda/heap/method_lookup.h"

void INVOKE_INTERFACE::fetchOperands(shared<BytecodeReader> reader) {
    index = uint(reader->readUint16());
    reader->readUint8(); // count
    reader->readUint8(); // zero
}

void INVOKE_INTERFACE::execute(shared<Frame> frame) {
    LOG_INFO("INVOKE_INTERFACE");
    auto cp = frame->method->klass->constantPool;
    LOG_INFO("INVOKE_INTERFACE: %1%", typeid(*cp->getConstant(index)).name());

    auto methodRef = std::dynamic_pointer_cast<heap::InterfaceMethodRefConstant>(cp->getConstant(index))->val;

    LOG_INFO("INVOKE_INTERFACE");
    auto resolvedMethod = methodRef->resolvedInterfaceMethod();
    LOG_INFO("INVOKE_INTERFACE");

    if (resolvedMethod->isStatic() || resolvedMethod->isPrivate()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError")
    }
    LOG_INFO("INVOKE_INTERFACE");

    auto ref = frame->operandStack->getRefFromTop(resolvedMethod->argSlotCount - 1);
    LOG_INFO("INVOKE_INTERFACE");

    if (ref == nullptr) {
        LOG_INFO("java.lang.NullPointerException");
    }
    if (!ref->klass->isImplements(methodRef->resolvedClass())) {
        LOG_INFO("java.lang.IncompatibleClassChangeError")
    }
    LOG_INFO("INVOKE_INTERFACE");

    auto methodToBoInvoked = heap::lookupMethodInClass(ref->klass, methodRef->name, methodRef->descriptor);
    LOG_INFO("INVOKE_INTERFACE");

    if (methodToBoInvoked == nullptr || methodToBoInvoked->isAbstract()) {
        LOG_INFO("java.lang.AbstractMethodError");
    }
    if (!methodToBoInvoked->isPublic()) {
        LOG_INFO("java.lang.IllegalAccessError");
    }
    invoke_Method(frame, methodToBoInvoked);
}
