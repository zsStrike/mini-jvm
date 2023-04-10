#include "../base/Instruction.h"

struct D2F : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct D2I : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct D2L : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};