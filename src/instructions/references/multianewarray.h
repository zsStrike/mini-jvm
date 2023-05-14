#pragma once

#include "../base/Instruction.h"

struct MULTI_ANEW_ARRAY : Instruction {
    u16 index;
    u8 dimensions;
    string toString() override { return "MULTI_ANEW_ARRAY"; }
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};