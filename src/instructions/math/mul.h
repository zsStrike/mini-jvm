#include "../base/Instruction.h"

struct IMUL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LMUL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct FMUL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct DMUL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};


