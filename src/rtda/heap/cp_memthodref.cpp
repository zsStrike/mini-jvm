//
// Created by strike on 4/11/23.
//

#include "cp_memthodref.h"
#include "constant_pool.h"
#include "method_lookup.h"

namespace heap {
    shared<MethodRef> newMethodRef(shared<ConstantPool> cp, shared<ConstantMethodrefInfo> refInfo) {
        auto ref = std::make_shared<MethodRef>();
        ref->cp = cp;
        ref->copyMemberRefInfo(std::static_pointer_cast<ConstantMemberrefInfo>(refInfo));
        return ref;
    }

    shared<Method> MethodRef::resolvedMethod() {
        if (method == nullptr) {
            resolveMethodRef();
        }
        return method;
    }

    void MethodRef::resolveMethodRef() {
        auto d = cp->klass;
        auto c = resolvedClass();
        if (c->isInterface()) {
            LOG_INFO("java.lang.IncompatibleClassChangeError")
        }
        auto method = lookupMethod(c, name, descriptor);
        if (method == nullptr) {
            LOG_INFO("java.lang.NoSuchMethodError");
        }
        if (!method->isAccessibleTo(d)) {
            LOG_INFO("java.lang.IllegalAccessError");
        }
        this->method = method;
    }

    shared<Method> MethodRef::lookupMethod(shared<Class> klass, shared<string> name, shared<string> descriptor) {
        auto method = lookupMethodInClass(klass, name, descriptor);
        if (method == nullptr) {
            method = lookupMethodInInterfaces(klass->interfaces, name, descriptor);
        }
        return method;
    }
}

