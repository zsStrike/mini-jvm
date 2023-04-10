#include "./ipush.h"

void BIPUSH::fetchOperands(shared<BytecodeReader> reader) {
    val = reader->readInt8();
}

void BIPUSH::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(val);
}

void SIPUSH::fetchOperands(shared<BytecodeReader> reader) {
    val = reader->readInt16();
}

void SIPUSH::execute(shared<Frame> frame) {
    frame->operandStack->pushInt(val);
}
