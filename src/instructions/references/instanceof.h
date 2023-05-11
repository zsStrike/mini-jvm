#pragma once
#include "../base/Instruction.h"

struct INSTANCE_OF : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};