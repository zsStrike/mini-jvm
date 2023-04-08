#pragma once
#include "../common/type.h"
#include <memory>
#include "ClassReader.h"
#include "ConstantPool.h"
#include "MemberInfo.h"
#include "../common/type.h"


struct ClassFile {
    u32                         magic;
    u16                         minorVersion;
    u16                         majorVersion;
    shared<ConstantPool>        constantPool;
    u16                         accessFlags;
    u16                         thisClass;
    u16                         superClass;
    shared_u16Buffer            interfaces;
    svs<MemberInfo>             fields;   
    svs<MemberInfo>             methods;
    svs<AttributeInfo>          attributes;

    void parse(shared_buffer buf);
    void read(ClassReader& reader);
    void readAndCheckMagic(ClassReader& reader);
    void readAndCheckVersion(ClassReader& reader);
    svs<MemberInfo> readMembers(ClassReader& reader);
    shared<MemberInfo> readMember(ClassReader& reader);

    shared<string> getClassName() const;
    shared<string> getSuperClassName() const;
    svs<string> getInterfaceNames() const;

    friend std::ostream& operator<<(std::ostream& out, const ClassFile& classFile);
};