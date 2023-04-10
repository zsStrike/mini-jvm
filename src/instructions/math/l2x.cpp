//
// Created by strike on 4/10/23.
//

#include "l2x.h"

void L2I::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt(i32(stack->popLong()));
}

void L2F::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushFloat(float32(stack->popLong()));
}

void L2D::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushDouble(float64(stack->popLong()));
}
