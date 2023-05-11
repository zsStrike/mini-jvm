//
// Created by strike on 5/9/23.
//

#include "new.h"


void NEW::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::static_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index));
    auto klass = classRef->val->resolvedClass();
    if (klass->isInterface() || klass->isAbstract()) {
        LOG_INFO("panic: java.lang.InstantiationError");
        return;
    }
    auto ref = klass->newObject();
    frame->operandStack->pushRef(ref);
}

string NEW::toString() {
    return "NEW";
}
