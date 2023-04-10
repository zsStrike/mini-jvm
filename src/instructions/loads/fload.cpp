#include "fload.h"

void fload(shared<Frame> frame, uint index) {
    frame->operandStack->pushFloat(frame->localVars->getFloat(index));
}

void FLOAD::execute(shared<Frame> frame) {
    fload(frame, index);
}

void FLOAD_0::execute(shared<Frame> frame) {
    fload(frame, 0);
}

void FLOAD_1::execute(shared<Frame> frame) {
    fload(frame, 1);
}

void FLOAD_2::execute(shared<Frame> frame) {
    fload(frame, 2);
}

void FLOAD_3::execute(shared<Frame> frame) {
    fload(frame, 3);
}
