#pragma once
#include "../common/type.h"
#include "ClassReader.h"
#include "ConstantPool.h"

struct AttributeInfo {
    virtual void readInfo(ClassReader& reader) {};
};

struct AttributeInfoWithConstantPool : AttributeInfo {
    shared<ConstantPool> cp;
    AttributeInfoWithConstantPool(shared<ConstantPool> cp_) : cp(cp_) {};
};

struct DeprecatedAttribute : AttributeInfo {};
struct SyntheticAttribute : AttributeInfo {};

struct UnparsedAttribute : AttributeInfo {
    shared<string> name;
    u32 length;
    shared_buffer info;
    UnparsedAttribute(shared<string> name_, u32 length_) : name(name_), length(length_) {}
    virtual void readInfo(ClassReader& reader);
};

struct ConstantValueAttribute : AttributeInfo {
    u16 constantValueIndex;
    virtual void readInfo(ClassReader& reader);
};

struct SourceFileAttribute : AttributeInfoWithConstantPool {
    u16 sourceFileIndex;
    using AttributeInfoWithConstantPool::AttributeInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
};

struct ExceptionTableEntry {
    u16 startPc;
    u16 endPc;
    u16 handlerPc;
    u16 catchType;
};

struct CodeAttribute : AttributeInfoWithConstantPool {
    u16 maxStack;
    u16 maxLocals;
    shared_buffer code;
    svs<AttributeInfo> attributes;
    svs<ExceptionTableEntry> exceptionTable;
    using AttributeInfoWithConstantPool::AttributeInfoWithConstantPool;
    virtual void readInfo(ClassReader& reader);
};

struct ExceptionsAttribute : AttributeInfo {
    shared_u16Buffer exceptionIndexTable;
    virtual void readInfo(ClassReader& reader);
};

struct LineNumberTableEntry {
    u16 startPc;
    u16 lineNumber;
};

struct LineNumberTableAttribute : AttributeInfo {
    svs<LineNumberTableEntry> lineNumberTable;
    virtual void readInfo(ClassReader& reader);
};

struct LocalVariableTableEntry {
    u16 startPc;
    u16 length;
    u16 nameIndex;
    u16 descriptorIndex;
    u16 index;
};

struct LocalVariableTableAttribute : AttributeInfo {
    svs<LocalVariableTableEntry> localVariableTable;
    virtual void readInfo(ClassReader& reader);
};


namespace attributeinfo {
    shared<AttributeInfo> newAttributeInfo(shared<string> attrName, u32 attrLen, shared<ConstantPool> cp);
    svs<AttributeInfo> readAttributes(ClassReader& reader, shared<ConstantPool> cp);
    shared<AttributeInfo> readAttribute(ClassReader& reader, shared<ConstantPool> cp);
}