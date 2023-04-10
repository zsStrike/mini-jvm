#include "../base/Instruction.h"

struct IFNULL : BranchInstruction {
    void execute(shared<Frame> frame) override;
};

struct IFNONULL : BranchInstruction {
    void execute(shared<Frame> frame) override;
};