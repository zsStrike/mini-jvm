#include "../base/Instruction.h"

struct GOTO_W : Instruction {
    int offset;
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};