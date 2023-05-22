#pragma once

#include "../common/type.h"
#include "../rtda/Frame.h"

namespace native {
    using NativeMethod = void (*)(shared<Frame>); // pointer type
    inline umap<string, NativeMethod> registry;

    void registerNativeMethod(shared<string> className, shared<string> methodName, shared<string> methodDescriptor, NativeMethod nativeMethod);
    NativeMethod findNativeMethod(shared<string> className, shared<string> methodName, shared<string> methodDescriptor);
    void initNativeMethodsRegistry();
 }

