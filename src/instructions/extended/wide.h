#include "../base/Instruction.h"

struct WIDE : Instruction {
    shared<Instruction> modifiedInstruction;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};