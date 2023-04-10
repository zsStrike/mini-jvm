//
// Created by strike on 4/10/23.
//

#include "if_icmp.h"
#include "../base/BranchLogic.h"

void IF_ICMPEQ::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 == v2) {
        branch(frame, offset);
    }
}

void IF_ICMPNE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 != v2) {
        branch(frame, offset);
    }
}

void IF_ICMPLT::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 < v2) {
        branch(frame, offset);
    }
}

void IF_ICMPLE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 <= v2) {
        branch(frame, offset);
    }
}

void IF_ICMPGT::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 > v2) {
        branch(frame, offset);
    }
}

void IF_ICMPGE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v1 >= v2) {
        branch(frame, offset);
    }
}
