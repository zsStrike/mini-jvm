//
// Created by strike on 4/10/23.
//

#include "d2x.h"

void D2F::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushFloat(float32(stack->popDouble()));
}

void D2I::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt(i32(stack->popDouble()));
}

void D2L::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushLong(i64(stack->popLong()));
}
