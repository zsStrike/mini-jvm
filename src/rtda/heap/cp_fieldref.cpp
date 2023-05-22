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
        auto d = cp->klass;
        auto c = resolvedClass();

        LOG_INFO("resolveFieldRef")
        auto field = lookupField(c, name, descriptor);

        if (field == nullptr) {
            LOG_INFO("panic: java.lang.NoSuchFieldError");
        }
        if (!field->isAccessibleTo(d)) {
            LOG_INFO("panic: java.lang.IllegalAccessError");
        }
        this->field = field; 
    }

    shared<Field> FieldRef::lookupField(shared<Class> c, shared<string> name, shared<string> descriptor) {
//        LOG_INFO("===lookupField: %s.%s%s", *c->name, *name, *descriptor);
//        if (c->fields == nullptr) {
//            LOG_INFO("+++lookupField: %s.%s%s", *c->name, *name, *descriptor);
//        }
        for (auto&& field : *c->fields) {
//            LOG_INFO("lookupField: %s.%s %s", *c->name, *field->name, *field->descriptor);
            if (*field->name == *name && *field->descriptor == *descriptor) {
//                LOG_INFO("found")
                return field;
            }
        }
//        if (c->interfaces == nullptr) {
//            LOG_INFO("+++lookupField: %s.%s%s", *c->name, *name, *descriptor);
//        }
        for (auto&& iface: *c->interfaces) {
            auto field = lookupField(iface, name, descriptor);
            if (field != nullptr) {
                return field;
            }
        }
        if (c->superClass != nullptr) {
            return lookupField(c->superClass, name, descriptor);
        }
//        LOG_INFO("lookupField not found: %s.%s%s", *c->name, *name, *descriptor);
        return nullptr;
    }

}

