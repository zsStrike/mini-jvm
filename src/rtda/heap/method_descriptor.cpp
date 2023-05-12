//
// Created by strike on 5/11/23.
//

#include "method_descriptor.h"

namespace heap {

    void MethodDescriptor::addParameterType(shared<string> t) {
        parameterTypes->push_back(t);
    }
}
