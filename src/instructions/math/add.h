#include "../base/Instruction.h"

struct IADD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LADD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct FADD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct DADD : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};


