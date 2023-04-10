#include "../base/Instruction.h"

struct TABLE_SWITCH : Instruction {
    i32 defaultOffset;
    i32 low;
    i32 high;
    shared<i32[]> jumpOffsets;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};