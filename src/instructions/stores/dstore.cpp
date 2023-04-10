#include "dstore.h"

void dstore(shared<Frame> frame, uint index) {
    frame->localVars->setDouble(index, frame->operandStack->popDouble());
}

void DSTORE::execute(shared<Frame> frame) {
    dstore(frame, index);
}

void DSTORE_0::execute(shared<Frame> frame) {
    dstore(frame, 0);
}

void DSTORE_1::execute(shared<Frame> frame) {
    dstore(frame, 1);
}

void DSTORE_2::execute(shared<Frame> frame) {
    dstore(frame, 2);
}

void DSTORE_3::execute(shared<Frame> frame) {
    dstore(frame, 3);
}
