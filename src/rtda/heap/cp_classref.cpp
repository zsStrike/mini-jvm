//
// Created by strike on 5/8/23.
//

#include "cp_classref.h"
#include "../../log/log.h"

namespace heap {
    shared<ClassRef> newClassRef(shared<ConstantPool> cp, shared<ConstantClassInfo> classInfo) {
//        LOG_INFO("newClassRef")
        auto ref = make_shared<ClassRef>();
        ref->cp = cp;
//        LOG_INFO("newClassRef, index = %d, name = %s", classInfo->nameIndex, *classInfo->cp->getUtf8(classInfo->nameIndex));
//        ref->className = classInfo->getName();
        ref->className = classInfo->cp->getUtf8(classInfo->nameIndex);
        return ref;
    }
}
