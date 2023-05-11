//
// Created by strike on 4/11/23.
//

#include "../../log/log.h"
#include "constant_pool.h"
#include "../../classfile/ConstantInfo.h"

namespace heap {
    shared<Constant> ConstantPool::getConstant(uint index) {
        if (index >= consts->size()) {
            LOG_INFO("bad index: %d", index);
        }
        return consts->at(index);
    }

    shared<ConstantPool> newConstantPool(shared<Class> klass, shared<::ConstantPool> cfCp) {
        auto size = cfCp->infos->size();
        auto consts = std::make_shared<vs<Constant>>(size);
        auto rtCp = make_shared<ConstantPool>();
        rtCp->klass = klass;
        rtCp->consts = consts;
        for (int i = 1; i < size; i++) {
            auto cpInfo = cfCp->infos->at(i);
//            LOG_INFO("Constant type name = %s", (typeid(*cpInfo).name()));
            if (typeid(*cpInfo) == typeid(ConstantIntegerInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantIntegerInfo>(cpInfo);
                consts->at(i) = make_shared<i32Constant>(info->val);
            } else if (typeid(*cpInfo) == typeid(ConstantFloatInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantFloatInfo>(cpInfo);
                consts->at(i) = make_shared<f32Constant>(info->val);
            } else if (typeid(*cpInfo) == typeid(ConstantLongInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantLongInfo>(cpInfo);
                consts->at(i) = make_shared<i64Constant>(info->val);
                i++;
            } else if (typeid(*cpInfo) == typeid(ConstantDoubleInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantDoubleInfo>(cpInfo);
                consts->at(i) = make_shared<f64Constant>(info->val);
                i++;
            } else if (typeid(*cpInfo) == typeid(ConstantStringInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantStringInfo>(cpInfo);
                consts->at(i) = make_shared<stringConstant>(info->cp->getUtf8(info->stringIndex));
            } else if (typeid(*cpInfo) == typeid(ConstantClassInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantClassInfo>(cpInfo);
//                LOG_INFO("nameIndex = %d", info->nameIndex);
                consts->at(i) = make_shared<ClassRefConstant>(newClassRef(rtCp, info));
            } else if (typeid(*cpInfo) == typeid(ConstantFieldrefInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantFieldrefInfo>(cpInfo);
                consts->at(i) = make_shared<FieldRefConstant>(newFieldRef(rtCp, info));
            } else if (typeid(*cpInfo) == typeid(ConstantMethodrefInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantMethodrefInfo>(cpInfo);
                consts->at(i) = make_shared<MethodRefConstant>(newMethodRef(rtCp, info));
            } else if (typeid(*cpInfo) == typeid(ConstantInterfaceMethodrefInfo)) {
                auto info = std::dynamic_pointer_cast<ConstantInterfaceMethodrefInfo>(cpInfo);
                consts->at(i) = make_shared<InterfaceMethodRefConstant>(newInterfaceMethodRef(rtCp, info));
            }

        }
        return rtCp;
    }

    shared<string> Constant::toString() {
        return make_shared<string>("Constant");
    }
}


