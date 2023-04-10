//
// Created by strike on 4/10/23.
//

#include "lookupswitch.h"
#include "../base/BranchLogic.h"

void LOOKUP_SWITCH::fetchOperands(shared<BytecodeReader> reader) {
    reader->skipPadding();
    defaultOffset = reader->readInt32();
    npairs = reader->readInt32();
    matchOffsets = reader->readInt32s(npairs * 2);
}

void LOOKUP_SWITCH::execute(shared<Frame> frame) {
    auto key = frame->operandStack->popInt();
    for (int i = 0; i < npairs * 2; i += 2) {
        if (matchOffsets[i] == key) {
            i32 offset = matchOffsets[i + 1];
            branch(frame, offset);
            return;
        }
    }
    branch(frame, defaultOffset);
}
