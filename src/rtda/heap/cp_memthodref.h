#pragma once
#include "./cp_memberref.h"
#include "method.h"

namespace heap {
//    struct Method;
    struct MethodRef : MemberRef {
        shared<Method> method;
    };
    shared<MethodRef> newMethodRef(shared<ConstantPool> cp, shared<ConstantMethodrefInfo> refInfo);
}