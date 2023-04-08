#include "Stack.h"
#include "../log/log.h"
#include <cstdlib>
#include <memory>
#include "Frame.h"

void Stack::push(shared<Frame> frame) {
    if (size >= maxSize) {
        LOG_INFO("stack overflow error");
        exit(-1);
    }
    if (_top != nullptr) {
        frame->lower = _top;
    }
    _top = frame;
    size++;
}

shared<Frame> Stack::pop() {
    if (_top == nullptr) {
        LOG_INFO("jvm stack is empty");
        exit(-1);
    }
    auto frame = _top;
    _top = frame->lower;
    frame->lower = nullptr;
    size--;
    return frame;
}

shared<Frame> Stack::top() {
    if (_top == nullptr) {
        LOG_INFO("jvm stack is empty");
        exit(-1);
    }
    return _top;
}

shared<Stack> stack::newStack(u32 maxSize) {
    return std::make_shared<Stack>(maxSize);
}
