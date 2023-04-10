#include "../base/Instruction.h"

struct DREM : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FREM : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct IREM : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LREM : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};