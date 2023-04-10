#include "../base/Instruction.h"

struct DSTORE : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct DSTORE_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DSTORE_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DSTORE_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DSTORE_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


