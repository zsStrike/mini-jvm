#include "../base/Instruction.h"

struct IINC : Instruction {
    uint index;
    i32 _const;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};