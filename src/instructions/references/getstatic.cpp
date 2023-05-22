//
// Created by strike on 5/10/23.
//

#include "getstatic.h"
#include "../base/class_init_logic.h"

void GET_STATIC::execute(shared<Frame> frame) {
    auto cp = frame->method->klass->constantPool;
    auto fieldRef = std::dynamic_pointer_cast<heap::FieldRefConstant>(cp->getConstant(index));
    auto field = fieldRef->val->resolvedField();
    auto klass = field->klass;
    if (!klass->initStarted) {
        frame->revertNextPc();
        initClass(frame->thread, klass);
        return;
    }
    if (!field->isStatic()) {
        LOG_INFO("java.lang.IncompatibleClassChangeError");
    }
    auto descriptor = field->descriptor;
    auto slotId = field->SlotId;
    auto slots = klass->staticVars;
    auto stack = frame->operandStack;
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

string GET_STATIC::toString() {
    return "GET_STATIC";
}
