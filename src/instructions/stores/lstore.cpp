#include "lstore.h"

void lstore(shared<Frame> frame, uint index) {
    frame->localVars->setLong(index, frame->operandStack->popLong());
}

void LSTORE::execute(shared<Frame> frame) {
    lstore(frame, index);
}

void LSTORE_0::execute(shared<Frame> frame) {
    lstore(frame, 0);
}

void LSTORE_1::execute(shared<Frame> frame) {
    lstore(frame, 1);
}

void LSTORE_2::execute(shared<Frame> frame) {
    lstore(frame, 2);
}

void LSTORE_3::execute(shared<Frame> frame) {
    lstore(frame, 3);
}
