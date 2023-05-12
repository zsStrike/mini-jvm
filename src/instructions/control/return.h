#pragma once

#include "../base/Instruction.h"

struct RETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "RETURN"; }
};

struct ARETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ARETURN"; }

};

struct DRETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DRETURN"; }

};

struct FRETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "FRETURN"; }

};

struct IRETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "IRETURN"; }

};

struct LRETURN : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "LRETURN"; }

};