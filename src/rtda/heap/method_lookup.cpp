//
// Created by strike on 5/11/23.
//

#include "method_lookup.h"
#include "class.h"

namespace heap {

    shared<Method> lookupMethodInClass(shared<Class> klass, shared<string> name, shared<string> descriptor) {
//        LOG_INFO("want method=%s%s", *name, *descriptor);
        for (shared<Class> c = klass; c != nullptr; c = c->superClass) {
//            LOG_INFO("class=%s", *c->name);
            for (shared<Method> m : *c->methods) {
//                LOG_INFO("method=%s%s", *m->name, *m->descriptor);
                if (*m->name == *name && *m->descriptor == *descriptor) {
//                    LOG_INFO("found method")
                    return m;
                }
            }
        }
        LOG_INFO("unable to find method: %s:%s%s", *klass->name, *name, *descriptor);
        return nullptr;
    }

    shared<Method> lookupMethodInInterfaces(svs<Class> ifaces, shared<string> name, shared<string> descriptor) {
        for (auto iface : *ifaces) {
            for (auto m : *iface->methods) {
                if (*m->name == *name && *m->descriptor == *descriptor) {
                    return m;
                }
            }
            auto m = lookupMethodInInterfaces(iface->interfaces, name, descriptor);
            if (m != nullptr) {
                return m;
            }
        }
        return nullptr;
    }
}
