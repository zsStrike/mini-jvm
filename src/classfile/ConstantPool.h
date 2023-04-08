#pragma once
#include "./ConstantInfo.h"
// #include "../common/type.h"
// #include "../common/type.h"

struct ConstantPool {
    svs<ConstantInfo> infos;
    shared<ConstantInfo> getConstantInfo(u16 index);
    tuple<shared<string>, shared<string>> getNameAndType(u16 index);
    shared<string> getClassName(u16 index);
    shared<string> getUtf8(u16 index);
};

namespace constantpool {
    shared<ConstantPool> readConstantPool(ClassReader &reader);
}