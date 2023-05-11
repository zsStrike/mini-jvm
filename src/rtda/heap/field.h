#pragma once
#include "class_member.h"
#include "../../classfile/MemberInfo.h"

namespace heap {
//    struct ClassMember;
    struct Field : ClassMember {
        uint SlotId{};
        uint constValueIndex{};
        bool isLongOrDouble();

        void copyAttributes(shared<MemberInfo> cfFields);
    };

    svs<Field> newFields(shared<Class> klass, svs<MemberInfo> cfFields);
}
