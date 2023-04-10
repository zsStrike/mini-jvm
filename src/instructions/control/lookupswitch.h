#include "../base/Instruction.h"

struct LOOKUP_SWITCH : Instruction {
    i32 defaultOffset;
    i32 npairs;
    shared<i32[]> matchOffsets;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};