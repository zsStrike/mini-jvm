//
// Created by strike on 4/11/23.
//

#include "cp_interface_methodref.h"
#include "constant_pool.h"
#include "method_lookup.h"

namespace heap {
    shared<InterfaceMethodRef> newInterfaceMethodRef(shared<heap::ConstantPool> cp,
                                                    shared<ConstantInterfaceMethodrefInfo> refInfo) {
        auto ref = std::make_shared<InterfaceMethodRef>();
        ref->cp = cp;
        ref->copyMemberRefInfo(std::dynamic_pointer_cast<::ConstantMemberrefInfo>(refInfo));
        return ref;
    }

    shared<Method> InterfaceMethodRef::resolvedInterfaceMethod() {
        if (method == nullptr) {
            resolvedInterfaceMethodRef();
        }
        return method;
    }

    void InterfaceMethodRef::resolvedInterfaceMethodRef() {
        auto d = cp->klass;
        auto c = resolvedClass();
        if (!c->isInterface()) {
            LOG_INFO("java.lang.IncompatibleClassChangeError");
        }
        auto method = lookupInterfaceMethod(c, name, descriptor);
        if (method == nullptr) {
            LOG_INFO("java.lang.NoSuchMethodError");
        }
        if (!method->isAccessibleTo(d)) {
            LOG_INFO("java.lang.IllegalAccessError");
        }
        this->method = method;
    }

    shared<Method>
    InterfaceMethodRef::lookupInterfaceMethod(shared<Class> iface, shared<string> name, shared<string> descriptor) {
        LOG_INFO("iface=%1% name=%2% descriptor=%3%", *iface->name, *name, *descriptor);
        for (auto m : *iface->methods) {
            if (*m->name == *name && *m->descriptor == *descriptor) {
                return m;
            }
        }
        return lookupMethodInInterfaces(iface->interfaces, name, descriptor);
    }
}

