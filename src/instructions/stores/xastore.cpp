//
// Created by strike on 5/12/23.
//

#include "xastore.h"
#include "boost/type_index.hpp"

inline void checkNotNull(heap::Object* ref) {
    if (ref == nullptr) {
        LOG_INFO("java.lang.NullPointerException");
    }
}

inline void checkIndex(int arrLen, int index) {
    if (index < 0 || index >= arrLen) {
        LOG_INFO("ArrayIndexOutOfBoundsException");
    }
}


void IASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popInt();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i32>*>(stack->popRef());
    checkNotNull(arrRef);
    auto ints = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    ints[index] = i32(val);
}

void AASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popRef();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<heap::Object*>*>(stack->popRef());
    checkNotNull(arrRef);
    auto objs = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    objs[index] = val;
}

void BASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popInt();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i8>*>(stack->popRef());
    checkNotNull(arrRef);
    auto bytes = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    bytes[index] = i8(val);
}

void CASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popInt();
    auto index = stack->popInt();
//    LOG_INFO("type = %s", boost::typeindex::type_id_runtime(*stack->getRefFromTop(0)).pretty_name())
    auto arrRef = dynamic_cast<heap::ArrayObject<char16_t>*>(stack->popRef());
//    LOG_INFO("xs");
    checkNotNull(arrRef);
    auto chars = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    chars[index] = u16(val);
}

void DASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popDouble();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<float64>*>(stack->popRef());
    checkNotNull(arrRef);
    auto doubles = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    doubles[index] = float64(val);
}

void FASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popFloat();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<float32>*>(stack->popRef());
    checkNotNull(arrRef);
    auto floats = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    floats[index] = float32(val);
}

void LASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popLong();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i64>*>(stack->popRef());
    checkNotNull(arrRef);
    auto longs = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    longs[index] = i64(val);
}

void SASTORE::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto val = stack->popInt();
    auto index = stack->popInt();
    auto arrRef = dynamic_cast<heap::ArrayObject<i16>*>(stack->popRef());
    checkNotNull(arrRef);
    auto shorts = arrRef->getData();
    checkIndex(arrRef->getLen(), index);
    shorts[index] = i16(val);
}
