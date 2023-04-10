#include "../base/Instruction.h"

struct IDIV : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LDIV : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct FDIV : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct DDIV : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};


