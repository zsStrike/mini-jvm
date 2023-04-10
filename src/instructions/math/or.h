#include "../base/Instruction.h"

struct IOR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LOR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

