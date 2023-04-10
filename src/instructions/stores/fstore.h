#include "../base/Instruction.h"

struct FSTORE : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct FSTORE_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FSTORE_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FSTORE_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct FSTORE_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


