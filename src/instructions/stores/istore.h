#include "../base/Instruction.h"

struct ISTORE : Index8Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ISTORE"; }
};

struct ISTORE_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ISTORE_0"; }
};

struct ISTORE_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ISTORE_1"; }
};

struct ISTORE_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ISTORE_2"; }
};

struct ISTORE_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ISTORE_3"; }
};


