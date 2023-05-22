//
// Created by strike on 4/10/23.
//

#include "sh.h"

void ISHL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    auto s = u32(v2) & 0x1f;
    stack->pushInt(v1 << s);
}

void ISHR::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    auto s = u32(v2) & 0x1f;
    stack->pushInt(v1 >> s);
}

void IUSHR::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popInt();
    auto s = u32(v2) & 0x1f;
    stack->pushInt(i32(u32(v1) >> s));
}

void LSHL::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;

    auto v2 = stack->popInt();

    auto v1 = stack->popLong();

    auto s = u32(v2) & 0x3f;
    stack->pushLong(v1 << s);

}

void LSHR::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popLong();
    auto s = u32(v2) & 0x3f;
    stack->pushLong(v1 >> s);
}

void LUSHR::execute(shared<Frame> frame) {
    auto stack = frame->operandStack;
    auto v2 = stack->popInt();
    auto v1 = stack->popLong();
    auto s = u32(v2) & 0x3f;
    stack->pushLong(i64(u64(v1) >> s));
}
