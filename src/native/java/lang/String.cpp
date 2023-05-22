//
// Created by strike on 5/19/23.
//

#include "String.hpp"
#include "../../../rtda/heap/string_pool.h"

namespace native::java::lang::String {

    void intern(shared<Frame> frame) {
        LOG_INFO("intern")
        auto thiz = frame->localVars->getThis();
        LOG_INFO("intern")

        auto interned = heap::internString(thiz);
        LOG_INFO("intern")

        frame->operandStack->pushRef(interned);
        LOG_INFO("intern")

    }


    void init() {
        auto className = make_shared<string>("java/lang/String");
        auto methodName = make_shared<string>("intern");
        auto methodDescriptor = make_shared<string>("()Ljava/lang/String;");
        registerNativeMethod(className, methodName, methodDescriptor, intern);
    }
}