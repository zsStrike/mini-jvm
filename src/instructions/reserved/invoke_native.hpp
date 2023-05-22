#pragma once

#include "../base/Instruction.h"

struct INVOKE_NATIVE : NoOperandInstruction {
    string toString() override { return "INVOKE_NATIVE"; }
    void execute(shared<Frame> frame) override;
};