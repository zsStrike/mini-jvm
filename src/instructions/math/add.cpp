//
// Created by strike on 4/10/23.
//

#include "add.h"

void IADD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    stack->pushInt(v1 + v2);
}

string IADD::toString() {
    return "IADD";
}

void LADD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    stack->pushLong(v1 + v2);
}

string LADD::toString() {
    return "LADD";
}

void FADD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    stack->pushFloat(v1 + v2);
}

string FADD::toString() {
    return "FADD";
}

void DADD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    stack->pushDouble(v1 + v2);
}

string DADD::toString() {
    return "DADD";
}




