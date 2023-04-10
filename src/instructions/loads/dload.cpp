#include "dload.h"

void dload(shared<Frame> frame, uint index) {
    frame->operandStack->pushDouble(frame->localVars->getDouble(index));
}

void DLOAD::execute(shared<Frame> frame) {
    dload(frame, index);
}

void DLOAD_0::execute(shared<Frame> frame) {
    dload(frame, 0);
}

void DLOAD_1::execute(shared<Frame> frame) {
    dload(frame, 1);
}

void DLOAD_2::execute(shared<Frame> frame) {
    dload(frame, 2);
}

void DLOAD_3::execute(shared<Frame> frame) {
    dload(frame, 3);
}
