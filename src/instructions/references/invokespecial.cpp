//
// Created by strike on 5/10/23.
//

#include "invokespecial.h"

void INVOKE_SPECIAL::execute(shared<Frame> frame) {
    frame->operandStack->popRef();
}
