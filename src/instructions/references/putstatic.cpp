//
// Created by strike on 5/10/23.
//

#include "putstatic.h"
#include "../base/class_init_logic.h"

void PUT_STATIC::execute(shared<Frame> frame) {
    auto currentMethod = frame->method;
    auto currentClass = currentMethod->klass;

    auto cp = currentClass->constantPool;
    auto fieldRef = std::static_pointer_cast<heap::FieldRefConstant>(cp->getConstant(index));

    auto field = fieldRef->val->resolvedField();

    auto klass = field->klass;
    if (!klass->initStarted) {
        frame->revertNextPc();
        initClass(frame->thread, klass);
        return;
    }
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
