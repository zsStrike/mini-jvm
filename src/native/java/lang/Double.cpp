//
// Created by strike on 5/19/23.
//

#include "Double.hpp"

namespace native::java::lang::Double {

    void doubleToRawLongBits(shared<Frame> frame) {
        auto value = frame->localVars->getDouble(0);
        frame->operandStack->pushLong(i64(*(reinterpret_cast<i64*>(&value))));
    }

    void longBitsToDouble(shared<Frame> frame) {
        auto value = frame->localVars->getLong(0);
        frame->operandStack->pushDouble(float64(*(reinterpret_cast<float64*>(&value))));
    }

    void init() {
        auto className = make_shared<string>("java/lang/Double");
        auto methodName = make_shared<string>("doubleToRawLongBits");
        auto methodDescriptor = make_shared<string>("(D)J");
        registerNativeMethod(className, methodName, methodDescriptor, doubleToRawLongBits);
        methodName = make_shared<string>("longBitsToDouble");
        methodDescriptor = make_shared<string>("(J)D");
        registerNativeMethod(className, methodName, methodDescriptor, longBitsToDouble);
    }
}