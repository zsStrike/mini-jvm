//
// Created by strike on 5/11/23.
//

#include "method_invoke_logic.h"

void invoke_Method(shared<Frame> invokerFrame, shared<heap::Method> method) {
    LOG_INFO("methodToBeInvoked: %s.%s%s", *method->klass->name, *method->name, *method->descriptor)
//    if (*method->name == "registerNatives") {
//        // TODO
//        LOG_INFO("calling registerNatives.............")
//        return;
//    }
    auto thread = invokerFrame->thread;
    auto newFrame = thread->newFrame(method);
    thread->pushFrame(newFrame);
    auto argSlotCount = int(method->argSlotCount);
    for (int i = argSlotCount - 1; i >= 0; i--) {
        auto slot = invokerFrame->operandStack->popSlot();
        newFrame->localVars->setSlot(i, slot);
    }
//    LOG_INFO("method = %1%, locaVars = %2%", *method->name, newFrame->localVars->toString());
}
