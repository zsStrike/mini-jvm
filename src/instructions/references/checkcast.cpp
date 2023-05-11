//
// Created by strike on 5/10/23.
//

#include "checkcast.h"

void CHECK_CAST::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    stack->pushRef(ref);
    if (ref == nullptr) {
        return;
    }
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::static_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index));
    auto klass = classRef->val->resolvedClass();
    if (!ref->isInstanceOf(klass)) {
        LOG_INFO("java.lang.ClassCastException");
    }
}

string CHECK_CAST::toString() {
    return "CHECK_CAST";
}
