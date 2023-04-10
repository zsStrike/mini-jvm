//
// Created by strike on 4/10/23.
//

#include "goto.h"
#include "../base/BranchLogic.h"

void GOTO::execute(shared<Frame> frame) {
    branch(frame, offset);
}
