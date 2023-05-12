#pragma once

#include "../base/Instruction.h"

struct INVOKE_VIRTUAL : Index16Instruction {
    string toString() override { return "INVOKE_VIRTUAL"; }
    void execute(shared<Frame> frame) override;
};