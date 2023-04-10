//
// Created by strike on 4/10/23.
//

#include "div.h"

void IDIV::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v2 == 0) {
        LOG_INFO("java.lang.ArithmeticException: / by zero");
    }
    stack->pushInt(v1 / v2);
}

string IDIV::toString() {
    return "IDIV";
}

void LDIV::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    if (v2 == 0) {
        LOG_INFO("java.lang.ArithmeticException: / by zero");
    }
    stack->pushLong(v1 / v2);
}

string LDIV::toString() {
    return "LDIV";
}

void FDIV::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    stack->pushFloat(v1 / v2);
}

string FDIV::toString() {
    return "FDIV";
}

void DDIV::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    stack->pushDouble(v1 / v2);
}

string DDIV::toString() {
    return "DDIV";
}




