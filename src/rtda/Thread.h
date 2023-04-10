#pragma once
#include "../common/type.h"
#include "Frame.h"
#include "Stack.h"

struct Frame;
struct Stack;

struct Thread {
    int pc;
    shared<Stack> stack;
    int getPc() { return pc; }
    void setPc(int pc) { this->pc = pc; }
    void pushFrame(shared<Frame> frame);
    shared<Frame> popFrame();
    shared<Frame> currentFrame();
    shared<Frame> newFrame(uint maxLocals, uint maxStack);
};

namespace thread {
    shared<Thread> newThread();
};
