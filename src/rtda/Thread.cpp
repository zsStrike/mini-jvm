#include "Thread.h"

using stack::newStack;

shared<Thread> thread::newThread() { 
    auto td = std::make_shared<Thread>();
    td->stack = newStack(1024);
    return td;
}

void Thread::pushFrame(shared<Frame> frame) {
    stack->push(frame);
}

shared<Frame> Thread::popFrame() {
    return stack->pop();
}

shared<Frame> Thread::currentFrame() {
    return stack->top();
}
