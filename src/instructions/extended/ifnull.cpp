//
// Created by strike on 4/10/23.
//

#include "ifnull.h"
#include "../base/BranchLogic.h"

void IFNULL::execute(shared<Frame> frame) {
    if (frame->operandStack->popRef() == nullptr) {
        branch(frame, offset);
    }
}

void IFNONULL::execute(shared<Frame> frame) {
    if (frame->operandStack->popRef() != nullptr) {
        branch(frame, offset);
    }
}
