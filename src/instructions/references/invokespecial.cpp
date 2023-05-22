//
// Created by strike on 5/10/23.
//

#include "invokespecial.h"
#include "../base/method_invoke_logic.h"
#include "../../rtda/heap/method_lookup.h"

void INVOKE_SPECIAL::execute(shared<Frame> frame) {
    auto currentClass = frame->method->klass;
    auto cp = currentClass->constantPool;
    auto methodRef = std::dynamic_pointer_cast<heap::MethodRefConstant>(cp->getConstant(index));
    auto resolvedClass = methodRef->val->resolvedClass();
    auto resolvedMethod = methodRef->val->resolvedMethod();

    if (*resolvedMethod->name == "<init>" && resolvedMethod->klass != resolvedClass) {
        LOG_INFO("java.lang.NoSuchMethodError");
    }

    if (resolvedMethod->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
    }
    auto ref = frame->operandStack->getRefFromTop(resolvedMethod->argSlotCount - 1);

    if (ref == nullptr) {
        LOG_INFO("java.lang.NullPointerException");
    }

    if (resolvedMethod->isProtected() &&
        resolvedMethod->klass->isSuperClassOf(currentClass) &&
        resolvedMethod->klass->getPackageName() != currentClass->getPackageName() &&
        ref->klass != currentClass &&
        !ref->klass->isSubClassOf(currentClass)) {
        LOG_INFO("java.lang.IllegalAccessError")
    }

    auto methodToBeInvoked = resolvedMethod;
    if (currentClass->isSuper() &&
        resolvedClass->isSuperClassOf(currentClass) &&
        *resolvedMethod->name != "<init>") {
        methodToBeInvoked = heap::lookupMethodInClass(currentClass->superClass, methodRef->val->name, methodRef->val->descriptor);
    }

    if (methodToBeInvoked == nullptr || methodToBeInvoked->isAbstract()) {
        LOG_INFO("java.lang.AbstractMethodError");
    }

    invoke_Method(frame, methodToBeInvoked);
}
