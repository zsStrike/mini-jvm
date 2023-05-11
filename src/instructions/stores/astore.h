#include "../base/Instruction.h"

struct ASTORE : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct ASTORE_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ASTORE_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ASTORE_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ASTORE_2"; }
};

struct ASTORE_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


