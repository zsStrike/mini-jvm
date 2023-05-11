#pragma once

#include "../base/Instruction.h"

struct INVOKE_SPECIAL : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "INVOKE_SPECIAL"; }
};