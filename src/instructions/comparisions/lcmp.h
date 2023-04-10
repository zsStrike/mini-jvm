#include "../base/Instruction.h"

struct LCMP : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};