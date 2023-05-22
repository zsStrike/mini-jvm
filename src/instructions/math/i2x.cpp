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

void I2B::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushBoolean(stack->popInt() == 1);
}

void I2C::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt((u16)stack->popInt());
}

void I2S::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt((i16)stack->popInt());
}
