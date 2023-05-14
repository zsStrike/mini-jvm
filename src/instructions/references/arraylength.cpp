//
// Created by strike on 5/12/23.
//

#include "arraylength.h"
#include "../../rtda/heap/Object.h"

void ARRAY_LENGTH::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto arrRef = stack->popRef();
    auto arrLen = arrRef->getLen();
    stack->pushInt(arrLen);
}
