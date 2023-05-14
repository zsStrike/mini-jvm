#pragma once
#include "../common/type.h"
#include "ClassReader.h"
#include "ConstantPool.h"
// #include "ConstantPool.h"
// #include "ConstantPool.h"

enum ConstantType {
   CONSTANT_Class                  = 7,
   CONSTANT_Fieldref               = 9,
   CONSTANT_Methodref              = 10,
   CONSTANT_InterfaceMethodref     = 11,
   CONSTANT_String                 = 8,
   CONSTANT_Integer                = 3,
   CONSTANT_Float                  = 4,
   CONSTANT_Long                   = 5,
   CONSTANT_Double                 = 6,
   CONSTANT_NameAndType            = 12,
   CONSTANT_Utf8                   = 1,
   CONSTANT_MethodHandle           = 15,
   CONSTANT_MethodType             = 16,
   CONSTANT_InvokeDynamic          = 18
};

struct ConstantPool;

struct ConstantInfo {
    virtual void readInfo(ClassReader& reader);
};

struct ConstantInfoWithConstantPool : ConstantInfo {
    shared<ConstantPool> cp;
    ConstantInfoWithConstantPool(shared<ConstantPool> cp_) : cp(cp_) {}
};

struct ConstantIntegerInfo : ConstantInfo {
    i32 val;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantLongInfo : ConstantInfo {
    i64 val;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantFloatInfo : ConstantInfo {
    float32 val;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantDoubleInfo : ConstantInfo {
    float64 val;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantUtf8Info : ConstantInfo {
    string str;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantStringInfo : ConstantInfoWithConstantPool {
    u16 stringIndex;
    using ConstantInfoWithConstantPool::ConstantInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantClassInfo : ConstantInfoWithConstantPool {
    u16 nameIndex;
    using ConstantInfoWithConstantPool::ConstantInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
    shared<string> getName();
};

struct ConstantNameAndTypeInfo : ConstantInfoWithConstantPool {
    u16 nameIndex;
    u16 descriptorIndex;
    using ConstantInfoWithConstantPool::ConstantInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
};

struct ConstantMemberrefInfo: ConstantInfoWithConstantPool {
    u16 classIndex;
    u16 nameAndTypeIndex;
    using ConstantInfoWithConstantPool::ConstantInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
    shared<string> getClassName();
    std::tuple<shared<string>, shared<string>> getNameAndDescriptor();
};

struct ConstantFieldrefInfo : ConstantMemberrefInfo {
    using ConstantMemberrefInfo::ConstantMemberrefInfo;
};

struct ConstantMethodrefInfo : ConstantMemberrefInfo {
    using ConstantMemberrefInfo::ConstantMemberrefInfo;
};

struct ConstantInterfaceMethodrefInfo : ConstantMemberrefInfo {
    using ConstantMemberrefInfo::ConstantMemberrefInfo;
};


struct ConstantMethodTypeInfo : ConstantInfo {
    u16 descriptorIndex;
    void readInfo(ClassReader &reader) override;
};


struct ConstantMethodHandleInfo : ConstantInfo {
    u8 referenceKind;
    u16 referenceIndex;
    void readInfo(ClassReader &reader) override;
};

struct ConstantInvokeDynamicInfo : ConstantInfo {
    u16 bootstrapMethodAttrIndex;
    u16 nameAndTypeIndex;
    void readInfo(ClassReader &reader) override;
};

namespace constantinfo {
    shared<ConstantInfo> newConstantInfo(u8 tag, shared<ConstantPool> cp);
    shared<ConstantInfo> readConstantInfo(ClassReader &reader, shared<ConstantPool> cp);
};