#include "../base/Instruction.h"

struct IF_ACMPEQ : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IF_ACMPNE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};