//
// Created by strike on 4/10/23.
//

#include "mul.h"

void IMUL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    stack->pushInt(v1 * v2);
}

string IMUL::toString() {
    return "IMUL";
}

void LMUL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    stack->pushLong(v1 * v2);
}

string LMUL::toString() {
    return "LMUL";
}

void FMUL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    stack->pushFloat(v1 * v2);
}

string FMUL::toString() {
    return "FMUL";
}

void DMUL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    stack->pushDouble(v1 * v2);
}

string DMUL::toString() {
    return "DMUL";
}




