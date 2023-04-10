#include "swap.h"

void SWAP::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot1 = stack->popSlot();
    auto slot2 = stack->popSlot();
    stack->pushSlot(slot1);
    stack->pushSlot(slot2);
}
