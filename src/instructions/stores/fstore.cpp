#include "fstore.h"

void fstore(shared<Frame> frame, uint index) {
    frame->localVars->setFloat(index, frame->operandStack->popFloat());
}

void FSTORE::execute(shared<Frame> frame) {
    fstore(frame, index);
}

void FSTORE_0::execute(shared<Frame> frame) {
    fstore(frame, 0);
}

void FSTORE_1::execute(shared<Frame> frame) {
    fstore(frame, 1);
}

void FSTORE_2::execute(shared<Frame> frame) {
    fstore(frame, 2);
}

void FSTORE_3::execute(shared<Frame> frame) {
    fstore(frame, 3);
}
