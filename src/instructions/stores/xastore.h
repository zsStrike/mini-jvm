#pragma once

#include "../base/Instruction.h"

struct AASTORE : NoOperandInstruction {
    string toString() override { return "AASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct BASTORE : NoOperandInstruction {
    string toString() override { return "BASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct CASTORE : NoOperandInstruction {
    string toString() override { return "CASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct DASTORE : NoOperandInstruction {
    string toString() override { return "DASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct FASTORE : NoOperandInstruction {
    string toString() override { return "FASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct IASTORE : NoOperandInstruction {
    string toString() override { return "IASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct LASTORE : NoOperandInstruction {
    string toString() override { return "LASTORE"; }
    void execute(shared<Frame> frame) override;
};

struct SASTORE : NoOperandInstruction {
    string toString() override { return "SASTORE"; }
    void execute(shared<Frame> frame) override;
};

