#include "../base/Instruction.h"
#include "../../log/log.h"

struct DUP : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP"; };
};

struct DUP_X1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP_X1"; };

};

struct DUP_X2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP_X2"; };

};

struct DUP2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP2"; };

};

struct DUP2_X1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP2_X1"; };

};

struct DUP2_X2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DUP2_X2"; };

};