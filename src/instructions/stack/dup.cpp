#include "dup.h"

// Duplicate the top operand stack value
void DUP::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot = stack->popSlot();
    stack->pushSlot(slot);
    stack->pushSlot(slot);
}

// Duplicate the top operand stack value and insert two values down
void DUP_X1::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    stack->pushSlot(slot1);
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
}

// Duplicate the top operand stack value and insert two or three values down
void DUP_X2::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    auto slot3 = stack->popSlot();
    stack->pushSlot(slot1);
    stack->pushSlot(slot3);
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
}

void DUP2::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
}

void DUP2_X1::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    auto slot3 = stack->popSlot();
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
    stack->pushSlot(slot3);
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);

}

void DUP2_X2::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    auto slot3 = stack->popSlot();
    auto slot4 = stack->popSlot();
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
    stack->pushSlot(slot4);
    stack->pushSlot(slot3);
    stack->pushSlot(slot2);
    stack->pushSlot(slot1);
}


