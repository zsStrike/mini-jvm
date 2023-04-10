#include "../base/Instruction.h"

struct ACONST_NULL : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ACONST_NULL"; };
};
struct DCONST_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DCONST_0"; };
};
struct DCONST_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "DCONST_1"; };
};
struct FCONST_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "FCONST_0"; };
};
struct FCONST_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "FCONST_1"; };
};
struct FCONST_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "FCONST_2"; };
};
struct ICONST_M1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_M1"; };
};
struct ICONST_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_0"; };
};
struct ICONST_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_1"; };
};
struct ICONST_2 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_2"; };
};
struct ICONST_3 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_3"; };
};
struct ICONST_4 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_4"; };
};
struct ICONST_5 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "ICONST_5"; };
};
struct LCONST_0 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "LCONST_0"; };
};
struct LCONST_1 : NoOperandInstruction {
    void execute(shared<Frame> frame) override;
    string toString() override { return "LCONST_1"; };
};