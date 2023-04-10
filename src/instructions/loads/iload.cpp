#include "iload.h"

void iload(shared<Frame> frame, uint index) {
    frame->operandStack->pushInt(frame->localVars->getInt(index));
}

void ILOAD::execute(shared<Frame> frame) {
    iload(frame, index);
}

void ILOAD_0::execute(shared<Frame> frame) {
    iload(frame, 0);
}

void ILOAD_1::execute(shared<Frame> frame) {
    iload(frame, 1);
}

void ILOAD_2::execute(shared<Frame> frame) {
    iload(frame, 2);
}

void ILOAD_3::execute(shared<Frame> frame) {
    iload(frame, 3);
}
