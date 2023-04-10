//
// Created by strike on 4/10/23.
//

#include "if_acmp.h"
#include "../base/BranchLogic.h"

void IF_ACMPEQ::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto ref2 = stack->popRef();
    auto ref1 = stack->popRef();
    if (ref1 == ref2) {
        branch(frame, offset);
    }
}

void IF_ACMPNE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto ref2 = stack->popRef();
    auto ref1 = stack->popRef();
    if (ref1 != ref2) {
        branch(frame, offset);
    }
}
