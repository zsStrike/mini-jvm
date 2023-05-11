#pragma once
#include "./cp_symref.h"
#include "../../classfile/ConstantInfo.h"

namespace heap {
//    struct SymRef;
//    struct ConstantMemberrefInfo;
    struct MemberRef : SymRef {
        shared<string> name;
        shared<string> descriptor;
        void copyMemberRefInfo(shared<ConstantMemberrefInfo> refInfo);
//        bool isAccessibleTo(shared<Class> d);
//
//        bool isProtected();
    };
}