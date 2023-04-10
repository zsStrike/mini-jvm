#include "../base/Instruction.h"

struct IXOR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LXOR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

