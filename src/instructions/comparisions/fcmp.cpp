//
// Created by strike on 4/10/23.
//

#include "fcmp.h"

void fcmp(shared<Frame> frame, bool gFlag) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    if (v1 > v2) stack->pushInt(1);
    else if (v1 == v2) stack->pushInt(0);
    else if (v1 < v2) stack->pushInt(-1);
    else if (gFlag) stack->pushInt(1);
    else stack->pushInt(-1);
}

void FCMPG::execute(shared<Frame> frame) {
    fcmp(frame, true);
}

void FCMPL::execute(shared<Frame> frame) {
    fcmp(frame, false);
}
