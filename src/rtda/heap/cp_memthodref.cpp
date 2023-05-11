//
// Created by strike on 4/11/23.
//

#include "cp_memthodref.h"

namespace heap {
    shared<MethodRef> newMethodRef(shared<ConstantPool> cp, shared<ConstantMethodrefInfo> refInfo) {
        auto ref = std::make_shared<MethodRef>();
        ref->cp = cp;
        ref->copyMemberRefInfo(std::static_pointer_cast<ConstantMemberrefInfo>(refInfo));
        return ref;
    }
}

