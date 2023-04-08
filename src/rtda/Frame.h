#pragma once
#include "../common/type.h"
#include "LocalVars.h"
#include "OperandStack.h"

struct Frame {
    shared<Frame> lower;
    shared<LocalVars> localVars;
    shared<OperandStack> operandStack;
};

namespace frame {
    shared<Frame> newFrame(u32 maxLocals, u32 maxStack);
}