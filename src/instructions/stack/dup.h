#include "../base/Instruction.h"
#include "../../log/log.h"

struct DUP : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DUP_X1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DUP_X2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DUP2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DUP2_X1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};

struct DUP2_X2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
};