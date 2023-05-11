#pragma once
#include "./class_member.h"
#include "../../classfile/MemberInfo.h"

namespace heap {
    struct Method : ClassMember {
        uint maxStack;
        uint maxLocals;
        shared_buffer code;

        void copyAttributes(shared<MemberInfo> cfMethod);
    };
    svs<Method> newMethods(shared<Class> klass, svs<MemberInfo> cfMethods);
}
