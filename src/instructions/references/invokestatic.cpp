//
// Created by strike on 5/12/23.
//

#include "invokestatic.h"
#include "../base/method_invoke_logic.h"
#include "../base/class_init_logic.h"

void INVOKE_STATIC::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto methodRef = cp->getConstant(index);
    auto resolvedMethod = std::dynamic_pointer_cast<heap::MethodRefConstant>(methodRef)->val->resolvedMethod();
    if (!resolvedMethod->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
    }
    auto klass = resolvedMethod->klass;
    if (!klass->initStarted) {
        frame->revertNextPc();
        initClass(frame->thread, klass);
        return;
    }
    invoke_Method(frame, resolvedMethod);
}
