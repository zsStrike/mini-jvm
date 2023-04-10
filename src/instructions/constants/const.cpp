#include "const.h"

void ACONST_NULL::execute(shared<Frame> frame) {
    frame->operandStack->pushRef(nullptr);
}

void DCONST_0::execute(shared<Frame> frame) {
    frame->operandStack->pushDouble(0.0);
}

void DCONST_1::execute(shared<Frame> frame) {
    frame->operandStack->pushDouble(1.0);
}

void FCONST_0::execute(shared<Frame> frame) {
    frame->operandStack->pushDouble(0.0f);
}

void FCONST_1::execute(shared<Frame> frame) {
    frame->operandStack->pushDouble(1.0f);
}

void FCONST_2::execute(shared<Frame> frame) {
    frame->operandStack->pushDouble(2.0f);
}

void ICONST_M1::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(-1);
}

void ICONST_0::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(0);
}

std::ostream& operator<<(std::ostream& out, const ICONST_0& inst) {
    LOG_INFO("ICONST_0");
    return out;
}

void ICONST_5::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(5);
}

void ICONST_1::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(1);
}

void ICONST_2::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(2);
}

void ICONST_3::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(3);
}

void ICONST_4::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(4);
}

void LCONST_0::execute(shared<Frame> frame) {
    frame->operandStack->pushLong(0L);
}

void LCONST_1::execute(shared<Frame> frame) {
    frame->operandStack->pushLong(1L);
}
