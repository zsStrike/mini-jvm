#pragma once
#include "../base/Instruction.h"

struct CHECK_CAST : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};