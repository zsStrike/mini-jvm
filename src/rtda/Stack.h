#pragma once
#include "../common/type.h"
#include "Frame.h"

struct Stack {
    u32 maxSize;
    u32 size;
    shared<Frame> _top;

    Stack(u32 maxSize_) : maxSize(maxSize_), size(0) {}

    void push(shared<Frame> frame);
    shared<Frame> pop();
    shared<Frame> top();
};

namespace stack {
    shared<Stack> newStack(u32 maxSize);
};

