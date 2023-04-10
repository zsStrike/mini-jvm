//
// Created by strike on 4/10/23.
//

#include "wide.h"
#include "../loads/iload.h"
#include "../loads/lload.h"
#include "../math/iinc.h"
#include "../loads/fload.h"
#include "../loads/dload.h"
#include "../loads/aload.h"
#include "../stores/lstore.h"
#include "../stores/istore.h"
#include "../stores/fstore.h"
#include "../stores/dstore.h"
#include "../stores/astore.h"
#include "../../log/log.h"

void WIDE::fetchOperands(shared<BytecodeReader> reader) {
    auto opcode = reader->readUint8();
    switch (opcode) {
        case 0x15: {    // iload
            auto inst = std::make_shared<ILOAD>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        }
        case 0x16: {    // lload
            auto inst = std::make_shared<LLOAD>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        }
        case 0x17: {
            auto inst = std::make_shared<FLOAD>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // fload
        case 0x18: {
            auto inst = std::make_shared<DLOAD>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // dload
        case 0x19: {
            auto inst = std::make_shared<ALOAD>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // aload
        case 0x36: {
            auto inst = std::make_shared<ISTORE>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // istore
        case 0x37: {
            auto inst = std::make_shared<LSTORE>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // lstore
        case 0x38: {
            auto inst = std::make_shared<FSTORE>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // fstore
        case 0x39: {
            auto inst = std::make_shared<DSTORE>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // dstore
        case 0x3a: {
            auto inst = std::make_shared<ASTORE>();
            inst->index = uint(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // astore
        case 0x84: {
            auto inst = std::make_shared<IINC>();
            inst->index = uint(reader->readInt16());
            inst->_const = i32(reader->readInt16());
            modifiedInstruction = inst;
            break;
        } // iinc
        case 0xa9: {
            LOG_INFO("%1%", "ret not implemented yet");
            return;
        } // ret
    }
}

void WIDE::execute(shared<Frame> frame) {
    modifiedInstruction->execute(frame);
}
