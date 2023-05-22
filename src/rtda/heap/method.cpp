//
// Created by strike on 4/11/23.
//

#include "method.h"
#include "method_descriptor_parser.h"
#include "../../log/log.h"

namespace heap {

    shared<Method> newMethod(shared<Class> klass, shared<MemberInfo> cfMethod) {
        auto method = std::make_shared<Method>();
        method->klass = klass;
        method->copyMemberInfo(cfMethod);
        method->copyAttributes(cfMethod);
        auto md = parseMethodDescriptor(method->descriptor);
        method->calcArgSlotCount(md->parameterTypes);
        if (method->isNative()) {
//            LOG_INFO("injectCodeAttribute");
            method->injectCodeAttribute(md->returnType);
        }
        return method;
    }

    svs<Method> newMethods(shared<Class> klass, svs<MemberInfo> cfMethods) {
        auto size = cfMethods->size();
        auto methods = std::make_shared<vs<Method>>(size);
        for (int i = 0; i < size; i++) {
            methods->at(i) = newMethod(klass, cfMethods->at(i));
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

    void Method::calcArgSlotCount(svs<string> paramTypes) {

        for (auto type : *paramTypes) {

            argSlotCount++;
            if (*type == "J" || *type == "D") {
                argSlotCount++;
            }
        }
        if (!isStatic()) {
            argSlotCount++;
        }

    }

    void Method::injectCodeAttribute(shared<string> returnType) {
        maxStack = 4;
        maxLocals = argSlotCount;
        code = make_shared<Buffer>();
        switch (returnType->at(0)) {
            case 'V': code->push_back(0xFE); code->push_back(0xB1); break; // return
            case 'D': code->push_back(0xFE); code->push_back(0xAF); break; // dreturn
            case 'F': code->push_back(0xFE); code->push_back(0xAE); break; // freturn
            case 'J': code->push_back(0xFE); code->push_back(0xAD); break; // lreturn
            case '[':
            case 'L': code->push_back(0xFE); code->push_back(0xB0); break; // areturn
            default: code->push_back(0xFE); code->push_back(0xAC); break; // ireturn
        }
    }
}

