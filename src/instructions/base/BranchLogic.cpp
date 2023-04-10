//
// Created by strike on 4/10/23.
//

#include "BranchLogic.h"

void branch(shared<Frame> frame, int offset) {
    auto pc = frame->thread->pc;
    frame->setNextPc(pc + offset);
}
