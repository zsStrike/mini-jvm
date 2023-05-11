//
// Created by strike on 4/11/23.
//

#include "cp_fieldref.h"
#include "../../log/log.h"
#include "constant_pool.h"

namespace heap {
    shared<FieldRef> newFieldRef(std::shared_ptr<heap::ConstantPool> cp, shared<ConstantFieldrefInfo> refInfo) {
        auto ref = std::make_shared<FieldRef>();
        ref->cp = cp;
        ref->copyMemberRefInfo(std::static_pointer_cast<ConstantMemberrefInfo>(refInfo));
        return ref;
    }



    shared<Field> FieldRef::resolvedField() {
        if (field == nullptr) {
            resolveFieldRef();
        }
        return field;
    }

    void FieldRef::resolveFieldRef() {
        LOG_INFO("FieldRef::resolveFieldRef")
        auto d = cp->klass;
        auto c = resolvedClass();
        LOG_INFO("FieldRef::resolveFieldRef")

        auto field = lookupField(c, name, descriptor);
        LOG_INFO("FieldRef::resolveFieldRef")

        if (field == nullptr) {
            LOG_INFO("panic: java.lang.NoSuchFieldError");
        }
        if (!field->isAccessibleTo(d)) {
            LOG_INFO("panic: java.lang.IllegalAccessError");
        }
        this->field = field; 
    }

    shared<Field> FieldRef::lookupField(shared<Class> c, shared<string> name, shared<string> descriptor) {
        for (auto&& field : *c->fields) {
            if (*field->name == *name && *field->descriptor == *descriptor) {
                return field;
            }
        }
        for (auto&& iface: *c->interfaces) {
            auto field = lookupField(iface, name, descriptor);
            if (field != nullptr) {
                return field;
            }
        }
        if (c->superClass != nullptr) {
            return lookupField(c->superClass, name, descriptor);
        }
        return nullptr;
    }

}

