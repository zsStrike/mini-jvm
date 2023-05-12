#pragma once
#include "./cp_memberref.h"
#include "method.h"

namespace heap {
//    struct Method;
//    struct ConstantInterfaceMethodrefInfo;
    struct InterfaceMethodRef : MemberRef {
        shared<Method> method;

        shared<Method> resolvedInterfaceMethod();
        shared<Method> lookupInterfaceMethod(shared<Class> iface, shared<string> name, shared<string> descriptor);
        void resolvedInterfaceMethodRef();

    };

    shared<InterfaceMethodRef> newInterfaceMethodRef(shared<ConstantPool> cp, shared<ConstantInterfaceMethodrefInfo> refInfo);

}