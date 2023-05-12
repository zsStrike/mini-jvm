//
// Created by strike on 4/11/23.
//

#include "method.h"
#include "method_descriptor_parser.h"
#include "../../log/log.h"

namespace heap {
    svs<Method> newMethods(shared<Class> klass, svs<MemberInfo> cfMethods) {
        auto size = cfMethods->size();
        auto methods = std::make_shared<vs<Method>>(size);
        for (int i = 0; i < size; i++) {
            auto method = make_shared<Method>();
            method->klass = klass;
            method->copyMemberInfo(cfMethods->at(i));
            method->copyAttributes(cfMethods->at(i));
            method->calcArgSlotCount();
            methods->at(i) = method;
        }
        return methods;
    }

    void Method::copyAttributes(shared<MemberInfo> cfMethod) {
        if (auto codeAttr = cfMethod->getCodeAttribute(); codeAttr != nullptr) {
            maxStack = codeAttr->maxStack;
            maxLocals = codeAttr->maxLocals;
            code = codeAttr->code;
        }
    }

    void Method::calcArgSlotCount() {
        auto parsedDescriptor = parseMethodDescriptor(descriptor);

        for (auto type : *parsedDescriptor->parameterTypes) {

            argSlotCount++;
            if (*type == "J" || *type == "D") {
                argSlotCount++;
            }
        }
        if (!isStatic()) {
            argSlotCount++;
        }

    }
}

