//
// Created by strike on 5/17/23.
//

#include "invoke_native.hpp"
#include "../../native/registry.hpp"

void INVOKE_NATIVE::execute(shared<Frame> frame) {
    auto method = frame->method;
    auto className = method->klass->name;
    auto methodName = method->name;
    auto methodDescriptor = method->descriptor;
    auto nativeMethod = native::findNativeMethod(className, methodName, methodDescriptor);
    if (nativeMethod == nullptr) {
        LOG_INFO("java.lang.UnsatisfiedLinkError: %s.%s%s", *className, *methodName, *methodDescriptor);
    }
    nativeMethod(frame);
}
