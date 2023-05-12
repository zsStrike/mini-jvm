#pragma once
#include "../common/type.h"
//#include "Frame.h"

struct Frame;

struct Stack {
    u32 maxSize;
    u32 size;
    shared<Frame> _top;

    Stack(u32 maxSize_) : maxSize(maxSize_), size(0) {}

    void push(shared<Frame> frame);
    shared<Frame> pop();
    shared<Frame> top();
    bool isEmpty() { return _top == nullptr; }
};

namespace stack {
    shared<Stack> newStack(u32 maxSize);
};

