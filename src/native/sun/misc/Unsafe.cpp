//
// Created by strike on 5/22/23.
//

#include "Unsafe.hpp"

namespace native::sun::misc::Unsafe {

    void arrayBaseOffset(shared<Frame> frame) {
        auto stack = frame->operandStack;
        stack->pushInt(0);
    }

    void arrayIndexScale(shared<Frame> frame) {
        auto stack = frame->operandStack;
        stack->pushInt(1);
    }

    void addressSize(shared<Frame> frame) {
        auto stack = frame->operandStack;
        stack->pushInt(8);
    }

    void init() {
        auto className = make_shared<string>("sun/misc/Unsafe");
        auto methodName = make_shared<string>("arrayBaseOffset");
        auto methodDescriptor = make_shared<string>("(Ljava/lang/Class;)I");
        registerNativeMethod(className, methodName, methodDescriptor, arrayBaseOffset);
        methodName = make_shared<string>("arrayIndexScale");
        methodDescriptor = make_shared<string>("(Ljava/lang/Class;)I");
        registerNativeMethod(className, methodName, methodDescriptor, arrayIndexScale);
        methodName = make_shared<string>("addressSize");
        methodDescriptor = make_shared<string>("()I");
        registerNativeMethod(className, methodName, methodDescriptor, addressSize);
    }
}
