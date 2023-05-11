#pragma once
#include "cp_symref.h"
#include "../../classfile/ConstantInfo.h"
//#include "constant_pool.h"

namespace heap {
//    struct SymRef;
    struct ClassRef : SymRef {

    };
    shared<ClassRef> newClassRef(shared<ConstantPool> cp, shared<ConstantClassInfo> classInfo);
}