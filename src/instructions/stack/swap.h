#include "../base/Instruction.h"

struct SWAP : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};