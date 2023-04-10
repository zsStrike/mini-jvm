#include "dup.h"

void DUP::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto slot = stack->popSlot();
    stack->pushSlot(slot);
    stack->pushSlot(slot);
}

void DUP_X1::execute(shared<Frame> frame) {
    LOG_INFO("unimplemented");
}

void DUP_X2::execute(shared<Frame> frame) {
    LOG_INFO("unimplemented");
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
    LOG_INFO("unimplemented");

}

void DUP2_X2::execute(shared<Frame> frame) {
    LOG_INFO("unimplemented");
}


