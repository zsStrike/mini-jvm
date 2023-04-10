#include "../base/Instruction.h"

struct DCMPG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DCMPL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

