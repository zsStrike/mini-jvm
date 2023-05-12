#pragma once
#include "../../common/type.h"
#include "../../log/log.h"
//#include "constant_pool.h"
//#include "class.h"

namespace heap {
    struct ConstantPool;
    struct Class;
    struct SymRef {
        shared<ConstantPool> cp;
        shared<string> className;
        shared<Class> klass;

        shared<Class> resolvedClass();
        void resolveClassRef();
    };
}