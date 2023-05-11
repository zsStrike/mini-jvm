#pragma once
#include "../base/Instruction.h"

struct PUT_FIELD : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};