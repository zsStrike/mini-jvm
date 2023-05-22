//
// Created by strike on 5/19/23.
//

#include "VM.hpp"
#include "../../../rtda/heap/string_pool.h"
#include "../../../instructions/base/method_invoke_logic.h"

namespace native::sun::misc::VM {
    void initialize(shared<Frame> frame) {
        auto vmClass = frame->method->klass;
        auto savedProps =vmClass->getRefVar(std::make_shared<string>("savedProps"), make_shared<string>("Ljava/util/Properties;"));
        auto key = heap::JString(vmClass->loader, make_shared<string>("foo"));
        auto val = heap::JString(vmClass->loader, make_shared<string>("bar"));
        frame->operandStack->pushRef(savedProps);
        frame->operandStack->pushRef(key);
        frame->operandStack->pushRef(val);
        auto propsClass = vmClass->loader->loadClass(make_shared<string>("java/util/Properties"));
        auto setPropMethod = propsClass->getInstanceMethod(make_shared<string>("setProperty"), make_shared<string>("(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;"));
        invoke_Method(frame, setPropMethod);

    }
    void init() {
        auto className = make_shared<string>("sun/misc/VM");
        auto methodName = make_shared<string>("initialize");
        auto methodDescriptor = make_shared<string>("()V");
        registerNativeMethod(className, methodName, methodDescriptor, initialize);
    }
}