//
// Created by strike on 5/9/23.
//

#include "new.h"
#include "../base/class_init_logic.h"

void NEW::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::static_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index));
    auto klass = classRef->val->resolvedClass();
    if (!klass->initStarted) {
        frame->revertNextPc();
        initClass(frame->thread, klass);
        return;
    }
    if (klass->isInterface() || klass->isAbstract()) {
        LOG_INFO("panic: java.lang.InstantiationError");
    }
    auto ref = klass->newObject();
    frame->operandStack->pushRef(ref);
}

string NEW::toString() {
    return "NEW";
}
