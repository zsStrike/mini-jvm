#include "../base/Instruction.h"

struct F2D : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct F2I : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct F2L : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};