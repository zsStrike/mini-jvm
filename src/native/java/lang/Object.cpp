//
// Created by strike on 5/18/23.
//

#include "Object.hpp"

namespace native::java::lang::Object {

    void getClass(shared<Frame> frame) {
        auto thiz = frame->localVars->getThis();
        auto klass = thiz->klass->jClass;
        frame->operandStack->pushRef(klass);
    }

    void hashCode(shared<Frame> frame) {
        auto thiz = frame->localVars->getThis();
        auto hash = i32(*reinterpret_cast<u32*>(thiz));
        frame->operandStack->pushInt(hash);
    }

    void clone(shared<Frame> frame) {
        auto thiz = frame->localVars->getThis();
        auto cloneable = thiz->klass->loader->loadClass(std::make_shared<string>("java/lang/Cloneable"));
        if (!thiz->klass->isImplements(cloneable)) {
            LOG_INFO("java.lang.CloneNotSupportedException");
        }
        frame->operandStack->pushRef(thiz->clone());
    }

    void init() {
        LOG_INFO("loading getClass native method");
        auto className = make_shared<string>("java/lang/Object");
        auto methodName = make_shared<string>("getClass");
        auto methodDescriptor = make_shared<string>("()Ljava/lang/Class;");
        registerNativeMethod(className, methodName, methodDescriptor, getClass);
        methodName = make_shared<string>("hashCode");
        methodDescriptor = make_shared<string>("()I");
        registerNativeMethod(className, methodName, methodDescriptor, hashCode);
        methodName = make_shared<string>("clone");
        methodDescriptor = make_shared<string>("()Ljava/lang/Object;");
        registerNativeMethod(className, methodName, methodDescriptor, clone);
    }
}
