#pragma once

#include "../../common/type.h"

namespace heap {
    struct MethodDescriptor {
        svs<string> parameterTypes;
        shared<string> returnType;

        MethodDescriptor() {
            parameterTypes = make_shared<vs<string>>(0);
        }

        void addParameterType(shared<string> t);
    };
}