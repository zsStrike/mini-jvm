#pragma once

#include "../base/Instruction.h"

struct INVOKE_INTERFACE : Instruction {
    uint index;
    // u8 count;
    // u8 zero;
    void fetchOperands(shared<BytecodeReader> reader) override;
    string toString() override { return "INVOKE_INTERFACE"; }
    void execute(shared<Frame> frame) override;
};