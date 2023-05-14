#include "AttributeInfo.h"
#include "./ConstantPool.h"
#include <memory>
#include "../log/log.h"

shared<AttributeInfo> attributeinfo::newAttributeInfo(shared<string> attrName,
                                                      u32 attrLen,
                                                      shared<ConstantPool> cp) {
    shared<AttributeInfo> attr = nullptr;
    if (attrName->compare("Code") == 0) {
        attr = std::make_shared<CodeAttribute>(cp);
    } else if (attrName->compare("ConstantValue") == 0) {
        attr = std::make_shared<ConstantValueAttribute>();
    } else if (attrName->compare("Deprecated") == 0) {
        attr = std::make_shared<DeprecatedAttribute>();
    } else if (attrName->compare("Exceptions") == 0) {
        attr = std::make_shared<ExceptionsAttribute>();
    } else if (attrName->compare("LineNumberTable") == 0) {
        attr = std::make_shared<LineNumberTableAttribute>();
    } else if (attrName->compare("LocalVariableTable") == 0) {
        attr = std::make_shared<LocalVariableTableAttribute>();
    } else if (attrName->compare("SourceFile") == 0) {
        attr = std::make_shared<SourceFileAttribute>(cp);
    } else if (attrName->compare("Synthetic") == 0) {
        attr = std::make_shared<SyntheticAttribute>();
    } else {
        attr = std::make_shared<UnparsedAttribute>(attrName, attrLen);
    }
    return std::static_pointer_cast<AttributeInfo>(attr);
}

svs<AttributeInfo> attributeinfo::readAttributes(ClassReader &reader,
                                                 shared<ConstantPool> cp) {
    u16 attributesCount = reader.readUint16();
    auto attrs = std::make_shared<vs<AttributeInfo>>(attributesCount);
    for (int i = 0; i < attributesCount; i++) {
        (*attrs)[i] = readAttribute(reader, cp);
    }
    return attrs;
}

shared<AttributeInfo> attributeinfo::readAttribute(ClassReader &reader,
                                                shared<ConstantPool> cp) {
    u16 attrNameIndex = reader.readUint16();
    auto attrName = cp->getUtf8(attrNameIndex);
    u32 attrLen = reader.readUint32();
//    LOG_INFO("attrName = %s attrLen = %d", *attrName, attrLen);
    auto attrInfo = newAttributeInfo(attrName, attrLen, cp);
    attrInfo->readInfo(reader);
    return attrInfo;
}

void SourceFileAttribute::readInfo(ClassReader &reader) {
    sourceFileIndex = reader.readUint16();
}

void ConstantValueAttribute::readInfo(ClassReader &reader) {
    constantValueIndex = reader.readUint16();
}

svs<ExceptionTableEntry> readExceptionTable(ClassReader &reader) {
    u16 exceptionTableLength = reader.readUint16();
    auto etes = std::make_shared<vs<ExceptionTableEntry>>(exceptionTableLength);
    for (int i = 0; i < exceptionTableLength; i++) {
        auto ete = std::make_shared<ExceptionTableEntry>();
        ete->startPc = reader.readUint16();
        ete->endPc = reader.readUint16();
        ete->handlerPc = reader.readUint16();
        ete->catchType = reader.readUint16();
        (*etes)[i] = ete;
    }
    return etes;
}


void CodeAttribute::readInfo(ClassReader &reader) {
    maxStack = reader.readUint16();
    maxLocals = reader.readUint16();
    u32 codeLength = reader.readUint32();
    code = reader.readBytes(codeLength);
    exceptionTable = readExceptionTable(reader);
    attributes = attributeinfo::readAttributes(reader, cp);
}

void ExceptionsAttribute::readInfo(ClassReader &reader) {
    exceptionIndexTable = reader.readUint16s();
}

void LineNumberTableAttribute::readInfo(ClassReader &reader) {
    u16 lineNumberTableLength = reader.readUint16();
    auto table = std::make_shared<vs<LineNumberTableEntry>>(lineNumberTableLength);
    for (int i = 0; i < lineNumberTableLength; i++) {
        auto entry = std::make_shared<LineNumberTableEntry>();
        entry->startPc = reader.readUint16();
        entry->lineNumber = reader.readUint16();
        (*table)[i] = entry;
    }
    lineNumberTable = table;
}

void LocalVariableTableAttribute::readInfo(ClassReader &reader) {
    u16 localVariableTableLength = reader.readUint16();
    auto table = std::make_shared<vs<LocalVariableTableEntry>>(localVariableTableLength);
    for (int i = 0; i < localVariableTableLength; i++) {
        auto entry = std::make_shared<LocalVariableTableEntry>();
        entry->startPc = reader.readUint16();
        entry->length = reader.readUint16();
        entry->nameIndex = reader.readUint16();
        entry->descriptorIndex = reader.readUint16();
        entry->index = reader.readUint16();
        (*table)[i] = entry;
    }
    localVariableTable = table;
}

void UnparsedAttribute::readInfo(ClassReader &reader) {
    info = reader.readBytes(length);
}


