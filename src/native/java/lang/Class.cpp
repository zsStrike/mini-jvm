//
// Created by strike on 5/18/23.
//

#include "Class.hpp"
#include "../../../rtda/heap/string_pool.h"

namespace native::java::lang::Class {
    void getPrimitiveClass(shared<Frame> frame) {
        auto nameObj = frame->localVars->getRef(0);
        auto name = heap::cppString(nameObj);
        auto loader = frame->method->klass->loader;
        auto klass = loader->loadClass(name)->jClass;
        frame->operandStack->pushRef(klass);
    }
    void getName0(shared<Frame> frame) {
        auto thiz = frame->localVars->getThis();
        auto klass = any_cast<shared<heap::Class>>(thiz->extra);
        auto name = klass->getJavaName();
        auto nameObj = heap::JString(klass->loader, name);
        frame->operandStack->pushRef(nameObj);
    }
    void desiredAssertionStatus0(shared<Frame> frame) {
        frame->operandStack->pushBoolean(false);
    }
    void init() {
        LOG_INFO("loading getPrimitiveClass native method");
        auto className = make_shared<string>("java/lang/Class");
        auto methodName = make_shared<string>("getPrimitiveClass");
        auto methodDescriptor = make_shared<string>("(Ljava/lang/String;)Ljava/lang/Class;");
        registerNativeMethod(className, methodName, methodDescriptor, getPrimitiveClass);
        LOG_INFO("loading getName0 native method");
        methodName = make_shared<string>("getName0");
        methodDescriptor = make_shared<string>("()Ljava/lang/String;");
        registerNativeMethod(className, methodName, methodDescriptor, getName0);
        LOG_INFO("loading desiredAssertionStatus0 native method");
        methodName = make_shared<string>("desiredAssertionStatus0");
        methodDescriptor = make_shared<string>("(Ljava/lang/Class;)Z");
        registerNativeMethod(className, methodName, methodDescriptor, desiredAssertionStatus0);
    }
}
