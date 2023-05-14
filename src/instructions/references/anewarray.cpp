//
// Created by strike on 5/12/23.
//

#include "anewarray.h"

void ANEW_ARRAY::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::dynamic_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index))->val;
    auto componentClass = classRef->resolvedClass();
    auto stack = frame->operandStack;
    auto count = stack->popInt();
    if (count < 0) {
        LOG_INFO("java.lang.NegativeArraySizeException");
    }
    auto arrClass = componentClass->arrayClass();
    auto arr = arrClass->newArray(count);
    stack->pushRef(arr);
}
