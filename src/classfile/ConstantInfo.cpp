#include "./ConstantInfo.h"
#include "../log/log.h"
#include "ConstantInfo.h"

shared<ConstantInfo> constantinfo::newConstantInfo(u8 tag,
                                                   shared<ConstantPool> cp) {
    switch (tag) {
        case CONSTANT_Integer: return std::make_shared<ConstantIntegerInfo>();
        case CONSTANT_Float: return std::make_shared<ConstantFloatInfo>();
        case CONSTANT_Long: return std::make_shared<ConstantLongInfo>();
        case CONSTANT_Double: return std::make_shared<ConstantDoubleInfo>();
        case CONSTANT_Utf8: return std::make_shared<ConstantUtf8Info>();
        case CONSTANT_String: return std::make_shared<ConstantStringInfo>(cp);
        case CONSTANT_Class: return std::make_shared<ConstantClassInfo>(cp);
        case CONSTANT_Fieldref: return std::make_shared<ConstantFieldrefInfo>(cp);
        case CONSTANT_MethodType: return std::make_shared<ConstantMethodTypeInfo>(cp);
        case CONSTANT_Methodref: return std::make_shared<ConstantMethodrefInfo>(cp);
        case CONSTANT_InterfaceMethodref: return std::make_shared<ConstantInterfaceMethodrefInfo>(cp);
        case CONSTANT_NameAndType: return std::make_shared<ConstantNameAndTypeInfo>(cp);
        case CONSTANT_MethodHandle: return std::make_shared<ConstantMethodHandleInfo>(cp);
        case CONSTANT_InvokeDynamic: return std::make_shared<ConstantInvokeDynamicInfo>(cp);
        default: LOG_INFO("bad tag"); return nullptr;
    }
}

shared<ConstantInfo> constantinfo::readConstantInfo(ClassReader &reader,
                                                    shared<ConstantPool> cp) {
    u8 tag = reader.readUint8();
    shared<ConstantInfo> sci = newConstantInfo(tag, cp);
    sci->readInfo(reader);
    return sci;
}
void ConstantInfo::readInfo(ClassReader &reader) {}

void ConstantIntegerInfo::readInfo(ClassReader &reader) {
    val = (i32) reader.readUint32();
}

void ConstantFloatInfo::readInfo(ClassReader &reader) {
    u32 bits = reader.readUint32();
    val = *reinterpret_cast<float32*>(&bits);
}

void ConstantLongInfo::readInfo(ClassReader &reader) {
    val = (i64) reader.readUint64();
}

void ConstantDoubleInfo::readInfo(ClassReader &reader) {
    u64 bits = reader.readUint64();
    val = *reinterpret_cast<float64*>(&bits);
}

string decodeMUTF8(shared_buffer bytes) {
    return string((char*)bytes->data(), bytes->size());
}

void ConstantUtf8Info::readInfo(ClassReader &reader) {
    u32 len = (u32) reader.readUint16();
    auto bytes = reader.readBytes(len);
    str = decodeMUTF8(bytes);
}

void ConstantStringInfo::readInfo(ClassReader &reader) {
    stringIndex = reader.readUint16();
}

void ConstantClassInfo::readInfo(ClassReader &reader) {
    nameIndex = reader.readUint16();
}

shared<string> ConstantClassInfo::getName() {
    return cp->getClassName(nameIndex);
}

void ConstantNameAndTypeInfo::readInfo(ClassReader &reader) {
    nameIndex = reader.readUint16();
    descriptorIndex = reader.readUint16();
}

void ConstantMemberrefInfo::readInfo(ClassReader &reader) {
    classIndex = reader.readUint16();
    nameAndTypeIndex = reader.readUint16();
}

shared<string> ConstantMemberrefInfo::getClassName() {
    return cp->getClassName(classIndex);
}

std::tuple<shared<string>, shared<string>> ConstantMemberrefInfo::getNameAndDescriptor() {
    return cp->getNameAndType(nameAndTypeIndex);
}

