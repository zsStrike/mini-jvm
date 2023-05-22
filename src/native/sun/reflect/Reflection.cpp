//
// Created by strike on 5/22/23.
//

#include "Reflection.hpp"

namespace native::sun::reflect::Reflection {
    void getCallerClass(shared<Frame> frame) {
        auto callerFrame = frame->thread->getFrame(2);
        auto callerClass = callerFrame->method->klass->jClass;
        frame->operandStack->pushRef(callerClass);
    }
    void init() {
        auto className = make_shared<string>("sun/reflect/Reflection");
        auto methodName = make_shared<string>("getCallerClass");
        auto methodDescriptor = make_shared<string>("()Ljava/lang/Class;");
        registerNativeMethod(className, methodName, methodDescriptor, getCallerClass);
    }
}