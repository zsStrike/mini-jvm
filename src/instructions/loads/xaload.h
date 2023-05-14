#pragma once

#include "../base/Instruction.h"

struct AALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "AALOAD"; }
};

struct BALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "BALOAD"; }
};

struct CALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "CALOAD"; }
};

struct DALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DALOAD"; }
};

struct FALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "FALOAD"; }
};

struct IALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "IALOAD"; }
};

struct LALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "LALOAD"; }
};

struct SALOAD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "SALOAD"; }
};

