#include "../base/Instruction.h"

struct IAND : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LAND : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

