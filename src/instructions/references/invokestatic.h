#pragma once

#include "../base/Instruction.h"

struct INVOKE_STATIC : Index16Instruction {
    string toString() override { return "INVOKE_STATIC"; }
    void execute(shared<Frame> frame) override;
};