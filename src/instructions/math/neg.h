#include "../base/Instruction.h"

struct INEG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct LNEG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct FNEG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};

struct DNEG : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override;
};


