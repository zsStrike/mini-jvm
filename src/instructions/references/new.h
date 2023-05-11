#pragma once
#include "../base/Instruction.h"

struct NEW : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};