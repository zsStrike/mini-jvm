#include "../base/Instruction.h"

struct I2L : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct I2F : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct I2D : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct I2B : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct I2C : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct I2S : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};