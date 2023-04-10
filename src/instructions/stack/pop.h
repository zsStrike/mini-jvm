#include "../base/Instruction.h"

struct POP : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct POP2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};