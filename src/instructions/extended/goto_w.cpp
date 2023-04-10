//
// Created by strike on 4/10/23.
//

#include "goto_w.h"
#include "../base/BranchLogic.h"

void GOTO_W::fetchOperands(shared<BytecodeReader> reader) {
    offset = int(reader->readInt32());
}

void GOTO_W::execute(shared<Frame> frame) {
    branch(frame, offset);
}


