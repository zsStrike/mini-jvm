//
// Created by strike on 4/10/23.
//

#include "ifcond.h"
#include "../base/BranchLogic.h"

void IFEQ::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val == 0) {
        branch(frame, offset);
    }
}

void IFNE::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val != 0) {
        branch(frame, offset);
    }
}

void IFLT::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val < 0) {
        branch(frame, offset);
    }
}

void IFLE::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val <= 0) {
        branch(frame, offset);
    }
}

void IFGT::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val > 0) {
        branch(frame, offset);
    }
}

void IFGE::execute(shared<Frame> frame) {
    auto val = frame->operandStack->popInt();
    if (val >= 0) {
        branch(frame, offset);
    }
}
