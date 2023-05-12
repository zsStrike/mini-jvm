#pragma once
#include "./cp_memberref.h"
#include "method.h"

namespace heap {
//    struct Method;
    struct MethodRef : MemberRef {
        shared<Method> method;

        shared<Method> resolvedMethod();

        void resolveMethodRef();

        shared<Method> lookupMethod(shared<Class> klass, shared<string> name, shared<string> descriptor);
    };
    shared<MethodRef> newMethodRef(shared<ConstantPool> cp, shared<ConstantMethodrefInfo> refInfo);
}