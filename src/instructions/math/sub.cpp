//
// Created by strike on 4/10/23.
//

#include "sub.h"

void ISUB::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    stack->pushInt(v1 - v2);
}

string ISUB::toString() {
    return "ISUB";
}

void LSUB::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    stack->pushLong(v1 - v2);
}

string LSUB::toString() {
    return "LSUB";
}

void FSUB::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    stack->pushFloat(v1 - v2);
}

string FSUB::toString() {
    return "FSUB";
}

void DSUB::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    stack->pushDouble(v1 - v2);
}

string DSUB::toString() {
    return "DSUB";
}




