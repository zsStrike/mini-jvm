//
// Created by strike on 4/11/23.
//

#include "cp_symref.h"
#include "../../log/log.h"
#include "class.h"

namespace heap {

    shared<Class> SymRef::resolvedClass() {
        if (klass == nullptr) {
            resolveClassRef();
        }
        return klass;
    }

    void SymRef::resolveClassRef() {
        auto d = cp->klass;
        auto c = d->loader->loadClass(className);
        if (!c->isAccessibleTo(d)) {
            LOG_INFO("panic: java.lang.IllegalAccessError");
        }
        klass = c;
    }
}

