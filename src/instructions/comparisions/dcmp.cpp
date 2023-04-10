//
// Created by strike on 4/10/23.
//

#include "dcmp.h"

void dcmp(shared<Frame> frame, bool gFlag) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    if (v1 > v2) stack->pushInt(1);
    else if (v1 == v2) stack->pushInt(0);
    else if (v1 < v2) stack->pushInt(-1);
    else if (gFlag) stack->pushInt(1);
    else stack->pushInt(-1);
}

void DCMPG::execute(shared<Frame> frame) {
    dcmp(frame, true);
}

void DCMPL::execute(shared<Frame> frame) {
    dcmp(frame, false);
}
