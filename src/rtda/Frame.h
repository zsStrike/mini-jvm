#pragma once
#include "../common/type.h"
#include "LocalVars.h"
#include "OperandStack.h"
#include "Thread.h"

struct Thread;

struct Frame {
    shared<Frame> lower;
    shared<LocalVars> localVars;
    shared<OperandStack> operandStack;
    shared<Thread> thread;
    int nextPc;
    void setNextPc(int nextPc) { this->nextPc = nextPc; }
};

namespace frame {
    shared<Frame> newFrame(shared<Thread> thread, u32 maxLocals, u32 maxStack);
}