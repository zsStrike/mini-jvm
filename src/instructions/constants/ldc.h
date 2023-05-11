#pragma once
#include "../base/Instruction.h"

struct LDC : Index8Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LDC_W : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LDC2_W : Index16Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};