//
// Created by strike on 5/19/23.
//

#include "System.hpp"
#include "../../registry.hpp"
#include "../../../common/type.h"

namespace native::java::lang::System {

    bool checkArrayCopy(heap::Object* src, heap::Object* dest) {
        auto srcClass = src->klass;
        auto destClass = dest->klass;
        if (!srcClass->isArray() || !destClass->isArray()) {
            return false;
        }
        if (srcClass->componentClass()->isPrimitive() ||
            destClass->componentClass()->isPrimitive()) {
            return srcClass == destClass;
        }
        return true;
    }

    void arraycopy(shared<Frame> frame) {
        auto vars = frame->localVars;
        auto src = vars->getRef(0);
        auto srcPos = vars->getInt(1);
        auto dest = vars->getRef(2);
        auto destPos = vars->getInt(3);
        auto length = vars->getInt(4);
        if (src == nullptr || dest == nullptr) {
            LOG_INFO("java.lang.NullPointerException");
        }
        if (!checkArrayCopy(src, dest)) {
            LOG_INFO("java.lang.ArrayStoreException");
        }
        LOG_INFO("arraycopy")
        if (srcPos < 0 || destPos < 0 || length < 0 ||
            srcPos + length > src->getLen() ||
            destPos + length > dest->getLen()) {
            LOG_INFO("java.lang.IndexOutOfBoundsException");
        }
        heap::arrayCopy(src, dest, srcPos, destPos, length);
    }
    void init() {
        auto className = make_shared<string>("java/lang/System");
        auto methodName = make_shared<string>("arraycopy");
        auto methodDescriptor = make_shared<string>("(Ljava/lang/Object;ILjava/lang/Object;II)V");
        registerNativeMethod(className, methodName, methodDescriptor, arraycopy);
    }
}
