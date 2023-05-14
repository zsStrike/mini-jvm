//
// Created by strike on 5/12/23.
//

#include "multianewarray.h"

void MULTI_ANEW_ARRAY::fetchOperands(shared<BytecodeReader> reader) {
    index = reader->readUint16();
    dimensions = reader->readUint8();
}

sv<i32> popAndCheckCounts(shared<OperandStack> stack, int dimensions) {
    auto counts = std::make_shared<vector<i32>>(dimensions);
    for (int i = dimensions - 1; i >= 0; i--) {
        counts->at(i) = stack->popInt();
        if (counts->at(i) < 0) {
            LOG_INFO("java.lang.NegativeArraySizeException")
        }
    }
    return counts;
}

heap::Object* newMultiDimensionalArray(sv<i32> counts, shared<heap::Class> arrClass) {
    auto count = counts->at(0);
    auto arr = arrClass->newArray(count);
    if (counts->size() > 1) {
        auto refs = dynamic_cast<heap::ArrayObject<heap::Object*>*>(arr);
        for (int i = 0; i < refs->getLen(); i++) {
            auto left = make_shared<vector<i32>>(counts->begin() + 1, counts->end());
            refs->getData()[i] = newMultiDimensionalArray(left, arrClass->componentClass());
        }
    }
    return arr;
}

void MULTI_ANEW_ARRAY::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto classRef = std::dynamic_pointer_cast<heap::ClassRefConstant>(cp->getConstant(index))->val;
    auto arrClass = classRef->resolvedClass();
    auto stack = frame->operandStack;
    auto counts = popAndCheckCounts(stack, dimensions);
    auto arr = newMultiDimensionalArray(counts, arrClass);
    stack->pushRef(arr);
}
