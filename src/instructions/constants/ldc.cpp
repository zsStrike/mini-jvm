//
// Created by strike on 5/10/23.
//

#include "ldc.h"
#include "../../rtda/heap/string_pool.h"

void ldc(shared<Frame> frame, uint index) {
    auto stack = frame->operandStack;
    auto klass = frame->method->klass;
    auto cp = frame->method->klass->constantPool;
    shared<heap::Constant> c = cp->getConstant(index);
    if (std::dynamic_pointer_cast<heap::i32Constant>(c)) {
        stack->pushInt(std::dynamic_pointer_cast<heap::i32Constant>(c)->val);
    } else if (std::dynamic_pointer_cast<heap::f32Constant>(c)) {
        stack->pushFloat(std::dynamic_pointer_cast<heap::f32Constant>(c)->val);
    } else if (std::dynamic_pointer_cast<heap::stringConstant>(c)) {
        auto internedStr = heap::JString(klass->loader, std::dynamic_pointer_cast<heap::stringConstant>(c)->val);
        stack->pushRef(internedStr);
    } else if (std::dynamic_pointer_cast<heap::ClassRefConstant>(c)) {

    } else {
        LOG_INFO("ldc: todo");
    }
}

void LDC::execute(shared<Frame> frame) {
    ldc(frame, index);
}

string LDC::toString() {
    return "LDC";
}

void LDC_W::execute(shared<Frame> frame) {
    ldc(frame, index);
}

string LDC_W::toString() {
    return "LDC_W";
}

void LDC2_W::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto cp = frame->method->klass->constantPool;
    auto c = cp->getConstant(index);
    if (std::dynamic_pointer_cast<heap::i64Constant>(c)) {
        stack->pushLong(std::dynamic_pointer_cast<heap::i64Constant>(c)->val);
    } else if (std::dynamic_pointer_cast<heap::f64Constant>(c)) {
        stack->pushDouble(std::dynamic_pointer_cast<heap::f64Constant>(c)->val);
    } else {
        LOG_INFO("java.lang.ClassFormatError");
    }
}

string LDC2_W::toString() {
    return "LDC2_W";
}
