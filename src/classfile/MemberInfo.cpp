#include "MemberInfo.h"
#include <memory>
#include "./AttributeInfo.h"

svs<MemberInfo> memberinfo::readerMembers(ClassReader& reader,
                                          shared<ConstantPool> cp) {
    u16 memberCount = reader.readUint16();
    auto members = std::make_shared<vs<MemberInfo>>(memberCount);
    for (int i = 0; i < memberCount; i++) {
        (*members)[i] = readerMember(reader, cp);
    }
    return members;
}

shared<MemberInfo> memberinfo::readerMember(ClassReader& reader,
                                            shared<ConstantPool> cp) {
    auto member = std::make_shared<MemberInfo>();
    member->cp = cp;
    member->accessFlags = reader.readUint16();
    member->nameIndex = reader.readUint16();
    member->descriptorIndex = reader.readUint16();
    member->attributes = attributeinfo::readAttributes(reader, cp);
    return member;
}

shared<CodeAttribute> MemberInfo::getCodeAttribute() {
    for (auto&& attrInfo : *attributes) {
        if (std::dynamic_pointer_cast<CodeAttribute>(attrInfo)) {
            return std::dynamic_pointer_cast<CodeAttribute>(attrInfo);
        }
    }
    return nullptr;
}

shared<ConstantValueAttribute> MemberInfo::getConstantValueAttribute() {
    for (auto&& attrInfo : *attributes) {
        if (std::dynamic_pointer_cast<ConstantValueAttribute>(attrInfo)) {
            return std::dynamic_pointer_cast<ConstantValueAttribute>(attrInfo);
        }
    }
    return nullptr;
}
