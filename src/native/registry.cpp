//
// Created by strike on 5/17/23.
//

#include "registry.hpp"
#include "java/lang/Object.hpp"
#include "java/lang/Class.hpp"
#include "java/lang/System.hpp"
#include "java/lang/Float.hpp"
#include "java/lang/Double.hpp"
#include "java/lang/String.hpp"
#include "sun/misc/VM.hpp"
#include "sun/misc/Unsafe.hpp"
#include "sun/reflect/Reflection.hpp"

namespace native {

    void emptyNativeMethod(shared<Frame>) {}

    void registerNativeMethod(shared<string> className, shared<string> methodName, shared<string> methodDescriptor,
                              NativeMethod nativeMethod) {
        string key = *className + "~" + *methodName + "~" + *methodDescriptor;
        registry[key] = nativeMethod;
    }



    NativeMethod
    findNativeMethod(shared<string> className, shared<string> methodName, shared<string> methodDescriptor) {
        string key = *className + "~" + *methodName + "~" + *methodDescriptor;
        LOG_INFO("key = %s", key);
//        for (auto [k, _] : registry) {
//            LOG_INFO("==key = %s", k);
//        }
        if (registry.count(key) == 1) {
            return registry[key];
        }
        if (*methodDescriptor == "()V" && *methodName == "registerNatives") {
            return emptyNativeMethod;
        }
        return nullptr;
    }

    void initNativeMethodsRegistry() {
        java::lang::Object::init();
        java::lang::Class::init();
        java::lang::System::init();
        java::lang::Float::init();
        java::lang::Double::init();
        java::lang::String::init();

        sun::misc::VM::init();
        sun::misc::Unsafe::init();

        sun::reflect::Reflection::init();
    }
}