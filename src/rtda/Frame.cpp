#include "Frame.h"

shared<Frame> frame::newFrame(shared<Thread> thread, u32 maxLocals, u32 maxStack) {
    auto frame = make_shared<Frame>();
    frame->thread = thread;
    frame->localVars = localvars::newLocalVars(maxLocals);
    frame->operandStack = operandstack::newOperandStack(maxStack);
    return frame;
}