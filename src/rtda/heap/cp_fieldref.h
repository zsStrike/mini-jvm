#pragma once
#include "./cp_memberref.h"
#include "../../classfile/ConstantInfo.h"
#include "field.h"

namespace heap {
//    struct Field;
    struct FieldRef : MemberRef {
        shared<Field> field;

        shared<Field> resolvedField();

        void resolveFieldRef();
        shared<Field> lookupField(shared<Class> c, shared<string> name, shared<string> descriptor);
    };

    shared<FieldRef> newFieldRef(std::shared_ptr<ConstantPool> cp, shared<ConstantFieldrefInfo> refInfo);

}
