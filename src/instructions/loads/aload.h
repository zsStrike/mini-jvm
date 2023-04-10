#include "../base/Instruction.h"

struct ALOAD : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct ALOAD_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ALOAD_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ALOAD_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ALOAD_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


