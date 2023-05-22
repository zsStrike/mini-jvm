#pragma once
#include "./class_member.h"
#include "../../classfile/MemberInfo.h"

namespace heap {
    struct Method : ClassMember {
        uint maxStack;
        uint maxLocals;
        shared_buffer code;
        uint argSlotCount;

        void copyAttributes(shared<MemberInfo> cfMethod);
        void calcArgSlotCount(svs<string> paramTypes);
        void injectCodeAttribute(shared<string> returnType);
    };
    svs<Method> newMethods(shared<Class> klass, svs<MemberInfo> cfMethods);
}
