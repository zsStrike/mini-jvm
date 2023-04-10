//
// Created by strike on 4/10/23.
//

#include "neg.h"

void INEG::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushInt(-stack->popInt());
}

string INEG::toString() {
    return "INEG";
}

void LNEG::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushLong(-stack->popLong());
}

string LNEG::toString() {
    return "LNEG";
}

void FNEG::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushFloat(-stack->popFloat());
}

string FNEG::toString() {
    return "FNEG";
}

void DNEG::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->pushDouble(-stack->popInt());
}

string DNEG::toString() {
    return "DNEG";
}
