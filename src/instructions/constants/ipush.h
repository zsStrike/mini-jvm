#include "../base/Instruction.h"

struct BIPUSH : Instruction {
    i8 val;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
    string toString() override { return "BIPUSH:" + std::to_string(val); }
};

struct SIPUSH : Instruction {
    i16 val;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
    string toString() override { return "SIPUSH:" + std::to_string(val); }
};

