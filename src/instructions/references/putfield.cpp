//
// Created by strike on 5/10/23.
//

#include "putfield.h"

void PUT_FIELD::execute(shared<Frame> frame) {
    auto currentMethod = frame->method;
    auto currentClass = currentMethod->klass;
    auto cp = currentClass->constantPool;
    auto fieldRef = std::static_pointer_cast<heap::FieldRefConstant>(cp->getConstant(index));
    auto field = fieldRef->val->resolvedField();
    auto klass = field->klass;
    if (field->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
        return;
    }
    if (field->isFinal()) {
        if (currentClass != klass || *currentMethod->name != "<init>") {
            LOG_INFO("java.lang.IllegalAccessError");
            return;
        }
    }
    auto descriptor = field->descriptor;
    auto slotId = field->SlotId;
    auto stack = frame->operandStack;
    switch (descriptor->at(0)) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I': {
            auto val = stack->popInt();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                LOG_INFO("java.lang.NullPointerException");
                break;
            }
            ref->fileds->setInt(slotId, val);
            break;
        }
        case 'F': {
            auto val = stack->popFloat();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                LOG_INFO("java.lang.NullPointerException");
                break;
            }
            ref->fileds->setFloat(slotId, val);
            break;
        }

        case 'J': {
            auto val = stack->popLong();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                LOG_INFO("java.lang.NullPointerException");
                break;
            }
            ref->fileds->setLong(slotId, val);
            break;
        }

        case 'D': {
            auto val = stack->popDouble();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                LOG_INFO("java.lang.NullPointerException");
                break;
            }
            ref->fileds->setDouble(slotId, val);
            break;
        }

        case 'L':
        case '[': {
            auto val = stack->popRef();
            auto ref = stack->popRef();
            if (ref == nullptr) {
                LOG_INFO("java.lang.NullPointerException");
                break;
            }
            ref->fileds->setRef(slotId, val);
            break;
        }
        default:
            LOG_INFO("bad descriptor: {}", *descriptor);
    }
}

string PUT_FIELD::toString() {
    return "PUT_FIELD";
}
