#include "OperandStack.h"
#include <memory>

shared<OperandStack> operandstack::newOperandStack(u32 maxStack) {
    if (maxStack > 0) {
        return std::make_shared<OperandStack>(maxStack);
    }
    return nullptr;
}

