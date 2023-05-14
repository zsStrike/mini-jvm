#pragma once

#include "../base/Instruction.h"

struct ANEW_ARRAY : Index16Instruction {
    string toString() override { return "ANEW_ARRAY"; }
    void execute(shared<Frame> frame) override;
};