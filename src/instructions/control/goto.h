#include "../base/Instruction.h"

struct GOTO : BranchInstruction {
    void execute(shared<Frame> frame) override;
};