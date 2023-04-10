#include "astore.h"

void astore(shared<Frame> frame, uint index) {
    frame->localVars->setRef(index, frame->operandStack->popRef());
}

void ASTORE::execute(shared<Frame> frame) {
    astore(frame, index);
}

void ASTORE_0::execute(shared<Frame> frame) {
    astore(frame, 0);
}

void ASTORE_1::execute(shared<Frame> frame) {
    astore(frame, 1);
}

void ASTORE_2::execute(shared<Frame> frame) {
    astore(frame, 2);
}

void ASTORE_3::execute(shared<Frame> frame) {
    astore(frame, 3);
}
