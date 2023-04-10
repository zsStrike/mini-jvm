#include "../base/Instruction.h"

struct FCMPG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FCMPL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

