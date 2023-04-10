//
// Created by strike on 4/10/23.
//

#include "lcmp.h"

void LCMP::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    if (v1 > v2) stack->pushInt(1);
    else if (v1 == v2) stack->pushInt(0);
    else stack->pushInt(-1);
}
