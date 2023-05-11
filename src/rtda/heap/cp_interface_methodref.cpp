//
// Created by strike on 4/11/23.
//

#include "cp_interface_methodref.h"

namespace heap {
    shared<InterfaceMethodRef> newInterfaceMethodRef(shared<heap::ConstantPool> cp,
                                                    shared<ConstantInterfaceMethodrefInfo> refInfo) {
        auto ref = std::make_shared<InterfaceMethodRef>();
        ref->cp = cp;
        ref->copyMemberRefInfo(std::dynamic_pointer_cast<::ConstantMemberrefInfo>(refInfo));
        return ref;
    }
}

