#include "../base/Instruction.h"

struct IF_ICMPEQ : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IF_ICMPNE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IF_ICMPLT : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IF_ICMPLE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IF_ICMPGT : BranchInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "IF_ICMPGT:" + std::to_string(offset); }
};

struct IF_ICMPGE : BranchInstruction {
    void execute(shared<Frame> frame) override;
};