//
// Created by strike on 5/10/23.
//

#include "putstatic.h"

void PUT_STATIC::execute(shared<Frame> frame) {
    LOG_INFO("PUT_STATIC")
    auto currentMethod = frame->method;
    auto currentClass = currentMethod->klass;
    LOG_INFO("PUT_STATIC")

    auto cp = currentClass->constantPool;
    auto fieldRef = std::static_pointer_cast<heap::FieldRefConstant>(cp->getConstant(index));
    LOG_INFO("PUT_STATIC")

    auto field = fieldRef->val->resolvedField();
    LOG_INFO("PUT_STATIC")

    auto klass = field->klass;
    LOG_INFO("PUT_STATIC")
    if (!field->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
        return;
    }
    if (field->isFinal()) {
        if (currentClass != klass || *currentMethod->name != "<clinit>") {
            LOG_INFO("java.lang.IllegalAccessError");
        }
    }
    auto descriptor = field->descriptor;
    auto slotId = field->SlotId;
    auto slots = klass->staticVars;
    auto stack = frame->operandStack;
    LOG_INFO("PUT_STATIC")
    switch (descriptor->at(0)) {
        case 'Z':
        case 'B':
        case 'C':
        case 'S':
        case 'I':
            slots->setInt(slotId, stack->popInt());
            break;
        case 'F':
            slots->setFloat(slotId, stack->popFloat());
            break;
        case 'J':
            slots->setLong(slotId, stack->popLong());
            break;
        case 'D':
            slots->setDouble(slotId, stack->popDouble());
            break;
        case 'L':
        case '[':
            slots->setRef(slotId, stack->popRef());
            break;
        default:
            LOG_INFO("bad descriptor: {}", *descriptor);
    }
}

string PUT_STATIC::toString() {
    return "PUT_STATIC";
}
