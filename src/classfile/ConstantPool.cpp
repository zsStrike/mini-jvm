#include "ConstantPool.h"
#include "ConstantInfo.h"
#include "../log/log.h"
#include <memory>

shared<ConstantPool> constantpool::readConstantPool(ClassReader& reader) {
    u16 cpCount = reader.readUint16();
    LOG_INFO("constantpoll count=%d", cpCount);
    auto scp = std::make_shared<ConstantPool>();
    scp->infos = std::make_shared<vs<ConstantInfo>>(cpCount);
    for (int i = 1; i < cpCount; i++) {
        auto ci = constantinfo::readConstantInfo(reader, scp);
        (*scp->infos)[i] = ci;
        if (std::dynamic_pointer_cast<ConstantLongInfo>(ci) || std::dynamic_pointer_cast<ConstantDoubleInfo>(ci)) {
            i++;
        }
    }
    return scp;
}

shared<ConstantInfo> ConstantPool::getConstantInfo(u16 index) {
    if (index >= infos->size()) {
        LOG_INFO("index out of bound");
        return nullptr;
    }
    return infos->at(index);
}

tuple<shared<string>, shared<string>> ConstantPool::getNameAndType(u16 index) {
    auto ntInfo = std::dynamic_pointer_cast<ConstantNameAndTypeInfo>(getConstantInfo(index));
    auto name = getUtf8(ntInfo->nameIndex);
    auto type = getUtf8(ntInfo->descriptorIndex);
    return std::make_tuple<shared<string>, shared<string>>(std::move(name), std::move(type));
}

shared<string> ConstantPool::getClassName(u16 index) {
    auto classInfo = std::dynamic_pointer_cast<ConstantClassInfo>(getConstantInfo(index));
    if (classInfo == nullptr) {
        LOG_INFO("nullptr");
    }
    return getUtf8(classInfo->nameIndex);
}

shared<string> ConstantPool::getUtf8(u16 index) {
    // LOG_INFO("index: %d", index);
    auto utf8Info = std::dynamic_pointer_cast<ConstantUtf8Info>(getConstantInfo(index));
    // LOG_INFO("index: %d", index);
    return std::make_shared<string>(utf8Info->str);
}
