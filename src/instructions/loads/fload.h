#include "../base/Instruction.h"

struct FLOAD : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct FLOAD_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FLOAD_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FLOAD_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FLOAD_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


