#include "aload.h"

void aload(shared<Frame> frame, uint index) {
    frame->operandStack->pushRef(frame->localVars->getRef(index));
}

void ALOAD::execute(shared<Frame> frame) {
    aload(frame, index);
}

void ALOAD_0::execute(shared<Frame> frame) {
    aload(frame, 0);
}

void ALOAD_1::execute(shared<Frame> frame) {
    aload(frame, 1);
}

void ALOAD_2::execute(shared<Frame> frame) {
    aload(frame, 2);
}

void ALOAD_3::execute(shared<Frame> frame) {
    aload(frame, 3);
}
