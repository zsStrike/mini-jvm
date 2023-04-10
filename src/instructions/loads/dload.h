#include "../base/Instruction.h"

struct DLOAD : Index8Instruction {
    void execute(shared<Frame> frame) override;
};

struct DLOAD_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DLOAD_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DLOAD_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DLOAD_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};


