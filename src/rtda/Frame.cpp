#include "Frame.h"

shared<Frame> frame::newFrame(u32 maxLocals, u32 maxStack) {
    auto frame = make_shared<Frame>();
    frame->localVars = localvars::newLocalVars(maxLocals);
    frame->operandStack = operandstack::newOperandStack(maxStack);
    return frame;
}