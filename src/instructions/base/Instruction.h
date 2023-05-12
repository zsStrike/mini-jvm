#pragma once
#include "../../common/type.h"
#include "../../rtda/Frame.h"
#include "./BytecodeReader.h"
#include "../../log/log.h"

struct Instruction {
    virtual void fetchOperands(shared<BytecodeReader> reader) {};
    virtual void execute(shared<Frame> frame) {
        LOG_INFO("default execute, you may not implemented for some Instruction");
    };
    virtual string toString() { return "Instruction"; };
};

struct NoOperandInstruction : Instruction {};

struct BranchInstruction : Instruction {
    int offset;
    virtual void fetchOperands(shared<BytecodeReader> reader) override;
};

struct Index8Instruction : Instruction {
    uint index;
    virtual void fetchOperands(shared<BytecodeReader> reader) override;
};

struct Index16Instruction : Instruction {
    uint index;
    virtual void fetchOperands(shared<BytecodeReader> reader) override;
};





