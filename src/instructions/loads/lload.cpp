#include "lload.h"

void lload(shared<Frame> frame, uint index) {
    frame->operandStack->pushLong(frame->localVars->getLong(index));
}

void LLOAD::execute(shared<Frame> frame) {
    lload(frame, index);
}

void LLOAD_0::execute(shared<Frame> frame) {
    lload(frame, 0);
}

void LLOAD_1::execute(shared<Frame> frame) {
    lload(frame, 1);
}

void LLOAD_2::execute(shared<Frame> frame) {
    lload(frame, 2);
}

void LLOAD_3::execute(shared<Frame> frame) {
    lload(frame, 3);
}
