#include "../base/Instruction.h"

struct ISUB : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LSUB : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct FSUB : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct DSUB : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};


