//
// Created by strike on 5/12/23.
//

#include "return.h"

void RETURN::execute(shared<Frame> frame) {
    frame->thread->popFrame();
}


void IRETURN::execute(shared<Frame> frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto retVal = currentFrame->operandStack->popInt();
    invokerFrame->operandStack->pushInt(retVal);
}

void LRETURN::execute(shared<Frame> frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto retVal = currentFrame->operandStack->popLong();
    invokerFrame->operandStack->pushLong(retVal);
}

void FRETURN::execute(shared<Frame> frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto retVal = currentFrame->operandStack->popFloat();
    invokerFrame->operandStack->pushFloat(retVal);
}

void DRETURN::execute(shared<Frame> frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto retVal = currentFrame->operandStack->popDouble();
    invokerFrame->operandStack->pushDouble(retVal);
}

void ARETURN::execute(shared<Frame> frame) {
    auto thread = frame->thread;
    auto currentFrame = thread->popFrame();
    auto invokerFrame = thread->currentFrame();
    auto retVal = currentFrame->operandStack->popRef();
    invokerFrame->operandStack->pushRef(retVal);
}
