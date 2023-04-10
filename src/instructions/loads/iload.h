#include "../base/Instruction.h"

struct ILOAD : Index8Instruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ILOAD"; }
};

struct ILOAD_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ILOAD_0"; }
};

struct ILOAD_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ILOAD_1"; }
};

struct ILOAD_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ILOAD_2"; }
};

struct ILOAD_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ILOAD_3"; }
};


