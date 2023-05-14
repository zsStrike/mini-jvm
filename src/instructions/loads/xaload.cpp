//
// Created by strike on 5/12/23.
//

#include "xaload.h"

void checkNotNull(heap::Object* ref) {
    if (ref == nullptr) {
        LOG_INFO("java.lang.NullPointerException");
    }
}

void checkIndex(int arrLen, int index) {
    if (index < 0 || index >= arrLen) {
        LOG_INFO("ArrayIndexOutOfBoundsException");
    }
}

void AALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<heap::Object*>*>(stack->popRef());
    checkNotNull(arrRef);
    auto refs = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushRef(refs[index]);
}

void BALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i8>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushInt(bytes[index]);
}

void CALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<u16>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushInt(bytes[index]);
}

void DALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<float64>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushDouble(bytes[index]);
}

void FALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<float32>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushFloat(bytes[index]);
}

void IALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i32>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushInt(bytes[index]);
}

void LALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i64>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushLong(bytes[index]);
}

void SALOAD::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i16>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    stack->pushInt(bytes[index]);
}
