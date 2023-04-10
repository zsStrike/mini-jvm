#include "../base/Instruction.h"

struct L2I : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct L2F : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct L2D : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};