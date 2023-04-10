#include "../base/Instruction.h"

struct IFEQ : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFNE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFLT : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFLE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFGT : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFGE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};