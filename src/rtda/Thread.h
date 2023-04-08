#pragma once
#include "../common/type.h"
#include "Stack.h"

struct Thread {
    int pc;
    shared<Stack> stack;
    int getPc() { return pc; }
    void setPc(int pc) { this->pc = pc; }
    void pushFrame(shared<Frame> frame);
    shared<Frame> popFrame();
    shared<Frame> currentFrame();
};

namespace thread {
    shared<Thread> newThread();
};
