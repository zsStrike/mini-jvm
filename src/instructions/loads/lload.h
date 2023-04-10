#include "../base/Instruction.h"

struct LLOAD : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct LLOAD_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LLOAD_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LLOAD_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LLOAD_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


