//
// Created by strike on 4/10/23.
//

#include "i2x.h"

void I2L::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushLong(i64(stack->popInt()));
}

void I2F::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushFloat(float32(stack->popInt()));
}

void I2D::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushDouble(float64(stack->popInt()));
}
