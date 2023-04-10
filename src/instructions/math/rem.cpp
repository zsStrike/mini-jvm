#include "rem.h"
#include "cmath"

void DREM::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popDouble();
    auto v1 = stack->popDouble();
    stack->pushDouble(fmodf64(v1, v2));
}

void FREM::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popFloat();
    auto v1 = stack->popFloat();
    stack->pushDouble(fmodf32(v1, v2));
}

void IREM::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    if (v2 == 0) {
        LOG_INFO("java.lang.ArithmeticException: / by zero");
        return;
    }
    stack->pushInt(v1 % v2);
}

void LREM::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popLong();
    auto v1 = stack->popLong();
    if (v2 == 0) {
        LOG_INFO("java.lang.ArithmeticException: / by zero");
        return;
    }
    stack->pushInt(v1 % v2);
}
