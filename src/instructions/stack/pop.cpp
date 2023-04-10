//
// Created by strike on 4/10/23.
//

#include "pop.h"

void POP::execute(shared<Frame> frame) {
    frame->operandStack->popSlot();
}


void POP2::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    stack->popSlot();
    stack->popSlot();
}
