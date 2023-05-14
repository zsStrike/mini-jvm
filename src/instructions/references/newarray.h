#pragma once

#include "../base/Instruction.h"

enum ARRAY_TYPE {
    AT_BOOLEAN     = 4,
    AT_CHAR        = 5,
    AT_FLOAT       = 6,
    AT_DOUBLE      = 7,
    AT_BYTE        = 8,
    AT_SHORT       = 9,
    AT_INT         = 10,
    AT_LONG        = 11
};

struct NEW_ARRAY : Instruction {
    u8 atype;
    string toString() override { return "NEW_ARRAY"; }
    void fetchOperands(shared<BytecodeReader> reader) override;
    void execute(shared<Frame> frame) override;
};