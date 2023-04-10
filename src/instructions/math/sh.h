#include "../base/Instruction.h"

struct ISHL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct ISHR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct IUSHR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LSHL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LSHR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct LUSHR : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};
