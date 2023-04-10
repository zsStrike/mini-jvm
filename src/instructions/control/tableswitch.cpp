//
// Created by strike on 4/10/23.
//

#include "tableswitch.h"
#include "../base/BranchLogic.h"

void TABLE_SWITCH::fetchOperands(shared<BytecodeReader> reader) {
    reader->skipPadding();
    defaultOffset = reader->readInt32();
    low = reader->readInt32();
    high = reader->readInt32();
    auto jumpOffsetsCount = high - low + 1;
    jumpOffsets = reader->readInt32s(jumpOffsetsCount);
}

void TABLE_SWITCH::execute(shared<Frame> frame) {
    auto index = frame->operandStack->popInt();
    int offset = defaultOffset;
    if (index >= low && index <= high) {
        offset = int(jumpOffsets[index - low]);
    }
    branch(frame, offset);
}
