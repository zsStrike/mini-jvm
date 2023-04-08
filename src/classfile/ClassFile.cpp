#include <algorithm>
#include <cstring>
#include <memory>
#include <cstdlib>
#include "ClassReader.h"
#include "ClassFile.h"
#include "../log/log.h"
#include "MemberInfo.h"
#include "AttributeInfo.h"

void ClassFile::parse(shared_buffer buf) {
    ClassReader cr(buf);
    read(cr);
}

void ClassFile::read(ClassReader &reader) {
    readAndCheckMagic(reader);
    readAndCheckVersion(reader);
    constantPool = constantpool::readConstantPool(reader);
    accessFlags = reader.readUint16();
    thisClass = reader.readUint16();
    superClass = reader.readUint16();
    interfaces = reader.readUint16s();
    fields = readMembers(reader);
    methods = readMembers(reader);
    attributes = attributeinfo::readAttributes(reader, constantPool);
}

void ClassFile::readAndCheckMagic(ClassReader &reader) {
    magic = reader.readUint32();
    LOG_INFO("magic: %x", magic);    
    if (magic != 0xCAFEBABE) {
        throw "wrong magic";
    }
}

void ClassFile::readAndCheckVersion(ClassReader &reader) {
    minorVersion = reader.readUint16();
    majorVersion = reader.readUint16();
    LOG_INFO("version %d.%d", majorVersion, minorVersion);    
    if (majorVersion == 45 || 
        minorVersion == 0 && majorVersion >= 46 && majorVersion <= 52) {
            return;
        }
    LOG_INFO("wrong verion detected");
}

svs<MemberInfo> ClassFile::readMembers(ClassReader &reader) {
    int memberCount = reader.readUint16();
    auto members = std::make_shared<vs<MemberInfo>>(memberCount);
    for (int i = 0; i < memberCount; i++) {
        (*members)[i] = readMember(reader);
    }
    return members;
}

shared<MemberInfo> ClassFile::readMember(ClassReader &reader) {
    auto member = std::make_shared<MemberInfo>();
    member->cp = constantPool;
    member->accessFlags = reader.readUint16();
    member->nameIndex = reader.readUint16();
    member->descriptorIndex = reader.readUint16();
    member->attributes = attributeinfo::readAttributes(reader, constantPool);
    return member;
}

shared<string> ClassFile::getClassName() const {
    return constantPool->getClassName(thisClass);
}

shared<string> ClassFile::getSuperClassName() const {
    if (superClass > 0) {
        return constantPool->getClassName(superClass);
    }
    return std::make_shared<string>("java.lang.Object");
}

svs<string> ClassFile::getInterfaceNames() const {
    int size = interfaces->size();
    auto names = std::make_shared<vs<string>>();
    for (int i = 0; i < size; i++) {
        if (interfaces->at(i) == 0) {
            continue;
        }
        names->push_back(constantPool->getClassName(interfaces->at(i)));
    }
    return names;
}

std::ostream &operator<<(std::ostream &out, const ClassFile &classFile) {
    out << boost::format("version: %1%.%2%\n") % classFile.majorVersion % classFile.minorVersion;
    out << boost::format("constant count: %1%\n") % classFile.constantPool->infos->size();
    out << boost::format("access flags: 0x%x\n") % classFile.accessFlags;
    out << boost::format("this class: %1%\n") % classFile.getClassName()->c_str();
    out << boost::format("super class: %1%\n") % classFile.getSuperClassName()->c_str();
    svs<string> interName = classFile.getInterfaceNames();
    out << boost::format("interfaces count: %1%\n") % interName->size();
    for (auto&& name: *interName) {
        out << *name << "\n";
    }
    out << std::endl;
    out << boost::format("fields count: %1%\n") % classFile.fields->size();
    for (auto&& field : *classFile.fields) {
        out << *field->getName() << "\n";
    }
    out << std::endl;
    out << boost::format("mehtods count: %1%\n") % classFile.methods->size();
    for (auto&& method : *classFile.methods) {
        out << *method->getName() << "\n";
    }
    out << std::endl;    
    return out;
}
