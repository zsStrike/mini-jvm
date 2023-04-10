#include "istore.h"

void istore(shared<Frame> frame, uint index) {
    frame->localVars->setInt(index, frame->operandStack->popInt());
}

void ISTORE::execute(shared<Frame> frame) {
    istore(frame, index);
}

void ISTORE_0::execute(shared<Frame> frame) {
    istore(frame, 0);
}

void ISTORE_1::execute(shared<Frame> frame) {
    istore(frame, 1);
}

void ISTORE_2::execute(shared<Frame> frame) {
    istore(frame, 2);
}

void ISTORE_3::execute(shared<Frame> frame) {
    istore(frame, 3);
}
