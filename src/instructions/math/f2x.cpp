//
// Created by strike on 4/10/23.
//

#include "f2x.h"

void F2D::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushDouble(float64(stack->popFloat()));
}

void F2I::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt(i32(stack->popFloat()));
}

void F2L::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushLong(i64(stack->popFloat()));
}
