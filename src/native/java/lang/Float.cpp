//
// Created by strike on 5/19/23.
//

#include "Float.hpp"

namespace native::java::lang::Float {

    void floatToRawIntBits(shared<Frame> frame) {
        auto value = frame->localVars->getFloat(0);
        frame->operandStack->pushInt(i32(*(reinterpret_cast<i32*>(&value))));
    }

    void init() {
        auto className = make_shared<string>("java/lang/Float");
        auto methodName = make_shared<string>("floatToRawIntBits");
        auto methodDescriptor = make_shared<string>("(F)I");
        registerNativeMethod(className, methodName, methodDescriptor, floatToRawIntBits);
    }
}