//
// Created by strike on 5/10/23.
//

#include "instanceof.h"

void INSTANCE_OF::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    if (ref == nullptr) {
        stack->pushInt(0);
        return;
    }
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::static_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index));
    auto klass = classRef->val->resolvedClass();
    if (ref->isInstanceOf(klass)) {
        stack->pushInt(1);
    } else {
        stack->pushInt(0);
    }
}

string INSTANCE_OF::toString() {
    return "INSTANCE_OF";
}
