#pragma once
#include "./cp_memberref.h"
#include "method.h"

namespace heap {
//    struct Method;
//    struct ConstantInterfaceMethodrefInfo;
    struct InterfaceMethodRef : MemberRef {
        shared<Method> method;

    };

    shared<InterfaceMethodRef> newInterfaceMethodRef(shared<ConstantPool> cp, shared<ConstantInterfaceMethodrefInfo> refInfo);

}