#include "../base/Instruction.h"

struct LSTORE : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct LSTORE_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LSTORE_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LSTORE_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LSTORE_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


