#pragma once
#include "ClassReader.h"
#include "ConstantPool.h"
#include "./AttributeInfo.h"

struct MemberInfo {
    shared<ConstantPool>        cp;
    u16                         accessFlags;
    u16                         nameIndex;
    u16                         descriptorIndex;
    svs<AttributeInfo>          attributes;
    
    shared<string> getName() {
        return cp->getUtf8(nameIndex);
    }

    shared<string> getDescriptor() {
        return cp->getUtf8(descriptorIndex);
    }

    shared<CodeAttribute> getCodeAttribute();
};

namespace memberinfo {
    svs<MemberInfo> readerMembers(ClassReader &reader, shared<ConstantPool> cp);
    shared<MemberInfo> readerMember(ClassReader &reader, shared<ConstantPool> cp);
};