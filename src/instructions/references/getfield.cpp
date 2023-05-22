//
// Created by strike on 5/10/23.
//

#include "getfield.h"
#include "../../rtda/heap/class_member.cpp"

void GET_FIELD::execute(shared<Frame> frame) {
    LOG_INFO("GET_FIELD")
    auto cp = frame->method->klass->constantPool;
    LOG_INFO("GET_FIELD")

    auto fieldRef = std::dynamic_pointer_cast<heap::FieldRefConstant>(cp->getConstant(index));
    LOG_INFO("GET_FIELD")

    auto field = fieldRef->val->resolvedField();
    LOG_INFO("GET_FIELD")

    if (field->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
    }
    LOG_INFO("GET_FIELD")

    auto stack = frame->operandStack;
    auto ref = stack->popRef();
    if (ref == nullptr) {
        LOG_INFO("java.lang.NullPointerException");
    }
    auto descriptor = field->descriptor;
    auto slotId = field->SlotId;
    auto slots = ref->fileds;
    LOG_INFO("GET_FIELD")
    switch (descriptor->at(0)) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            stack->pushInt(slots->getInt(slotId));
            break;
        case 'F':
            stack->pushFloat(slots->getFloat(slotId));
            break;
        case 'J':
            stack->pushLong(slots->getLong(slotId));
            break;
        case 'D':
            stack->pushDouble(slots->getDouble(slotId));
            break;
        case 'L':
        case '[':
            stack->pushRef(slots->getRef(slotId));
            break;
        default:
            LOG_INFO("bad descriptor: {}", *descriptor);
    }
}

string GET_FIELD::toString() {
    return "GET_FIELD";
}
