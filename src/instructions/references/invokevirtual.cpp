//
// Created by strike on 5/12/23.
//

#include "invokevirtual.h"
#include "../base/method_invoke_logic.h"
#include "../../rtda/heap/method_lookup.h"
#include "../../rtda/heap/string_pool.h"

void println(shared<OperandStack> stack, shared<string> descriptor) {
//    LOG_INFO("descrptor=%1%", *descriptor)
    if (*descriptor == "(Z)V") { LOG_INFO("%1%", stack->popInt() != 0 ? "true" : "false"); }
    else if (*descriptor == "(C)V") { LOG_INFO("%1%", stack->popInt()); }
    else if (*descriptor == "(B)V") { LOG_INFO("%1%", stack->popInt()); }
    else if (*descriptor == "(S)V") { LOG_INFO("%1%", stack->popInt()); }
    else if (*descriptor == "(I)V") { LOG_INFO("%1%", stack->popInt()); }
    else if (*descriptor == "(F)V") { LOG_INFO("%1%", stack->popFloat()); }
    else if (*descriptor == "(J)V") { LOG_INFO("%1%", stack->popLong()); }
    else if (*descriptor == "(D)V") { LOG_INFO("%1%", stack->popDouble()); }
    else if (*descriptor == "(Ljava/lang/String;)V") {
        auto jStr = stack->popRef();
        auto cppStr = heap::cppString(jStr);
        LOG_INFO(*cppStr);
    } else { LOG_INFO("println: %s", *descriptor); }
    stack->popRef();
}

void INVOKE_VIRTUAL::execute(shared<Frame> frame) {
    auto currentClass = frame->method->klass;
    auto cp = currentClass->constantPool;
    auto methodRef = std::dynamic_pointer_cast<heap::MethodRefConstant>(cp->getConstant(index))->val;
    auto resolvedMethod = methodRef->resolvedMethod();
    if (resolvedMethod->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
    }
    auto ref = frame->operandStack->getRefFromTop(resolvedMethod->argSlotCount - 1);
    if (ref == nullptr) {
        // TODO: hack System.out.println
        if (*methodRef->name == "println") {
            println(frame->operandStack, methodRef->descriptor);
            return;
//            LOG_INFO("oprandStack = %s", frame->operandStack->toString());
        }
        LOG_INFO("java.lang.NullPointerException");
    }
    if (resolvedMethod->isProtected() &&
        resolvedMethod->klass->isSuperClassOf(currentClass) &&
        resolvedMethod->klass->getPackageName() != currentClass->getPackageName() &&
        ref->klass != currentClass &&
        !ref->klass->isSubClassOf(currentClass)) {
        if (!(ref->klass->isArray() && *resolvedMethod->name == "clone")) {
            LOG_INFO("java.lang.IllegalAccessError");
        }
    }
    auto methodToBeInvoked = heap::lookupMethodInClass(ref->klass, methodRef->name, methodRef->descriptor);
    if (methodToBeInvoked == nullptr || methodToBeInvoked->isAbstract()) {
        LOG_INFO("java.lang.AbstractMethodError");
    }
    invoke_Method(frame, methodToBeInvoked);
}
