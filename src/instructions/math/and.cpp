//
// Created by strike on 4/10/23.
//

#include "and.h"

void IAND::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    stack->pushInt(v1 & v2);
}


void LAND::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    stack->pushLong(v1 & v2);
}
