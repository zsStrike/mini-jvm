#pragma once

#include "../base/Instruction.h"

struct ARRAY_LENGTH : NoOperandInstruction {
    string toString() override { return "ARRAY_LENGTH"; }
    void execute(shared<Frame> frame) override;
};