//
// Created by strike on 4/10/23.
//

#include "iinc.h"

void IINC::fetchOperands(shared<BytecodeReader> reader) {
    index = reader->readUint8();
    _const = reader->readInt8();
}

void IINC::execute(shared<Frame> frame) {
    auto localVars = frame->localVars;
    auto val = localVars->getInt(index);
    val += _const;
    localVars->setInt(index, val);
}
