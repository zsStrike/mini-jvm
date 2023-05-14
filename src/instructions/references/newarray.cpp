//
// Created by strike on 5/12/23.
//

#include "newarray.h"

void NEW_ARRAY::fetchOperands(shared<BytecodeReader> reader) {
    atype = reader->readUint8();
}

shared<heap::Class> getPrimitiveArrayClass(shared<heap::ClassLoader> loader, u8 atype) {
    switch (atype) {
        case AT_BOOLEAN: return loader->loadClass(std::make_shared<string>("[Z"));
        case AT_BYTE: return loader->loadClass(std::make_shared<string>("[B"));
        case AT_CHAR: return loader->loadClass(std::make_shared<string>("[C"));
        case AT_SHORT: return loader->loadClass(std::make_shared<string>("[S"));
        case AT_INT: return loader->loadClass(std::make_shared<string>("[I"));
        case AT_LONG: return loader->loadClass(std::make_shared<string>("[J"));
        case AT_FLOAT: return loader->loadClass(std::make_shared<string>("[F"));
        case AT_DOUBLE: return loader->loadClass(std::make_shared<string>("[D"));
        default: LOG_INFO("Invalid atype: %d", atype); return nullptr;
    }
}

void NEW_ARRAY::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto count = stack->popInt();
    if (count < 0) {
        LOG_INFO("java.lang.NegativeArraySizeException");
    }
    auto classLoader = frame->method->klass->loader;
    auto arrClass = getPrimitiveArrayClass(classLoader, atype);
    auto arr = arrClass->newArray(count);
    stack->pushRef(arr);
}
