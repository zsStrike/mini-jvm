#include "Instruction.h"

void BranchInstruction::fetchOperands(shared<BytecodeReader> reader) {
    offset = int (reader->readInt16());
}

void Index8Instruction::fetchOperands(shared<BytecodeReader> reader) {
    index = uint (reader->readUint8());
}

void Index16Instruction::fetchOperands(shared<BytecodeReader> reader) {
    index = uint (reader->readUint16());
}
