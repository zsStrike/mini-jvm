#include "../../common/type.h"
#include "../../log/log.h"

struct BytecodeReader {
    shared_buffer code;
    int pc = 0;
    void reset(shared_buffer code, int pc) {
        this->code = code;
        this->pc = pc;
    }
    u8 readUint8() { return code->at(pc++); }
    i8 readInt8() { return i8 (readUint8()); }
    u16 readUint16() {
        u16 high = u16 (readUint8());
        u16 low = u16 (readUint8());
        return (high << 8) | low;
    }
    i16 readInt16() {
        return i16(readUint16());
    }
    i32 readInt32() {
        u32 high = u32 (readUint16());
        u32 low = u32 (readInt16());
        return i32 ((high << 16) | low);
    }
    void skipPadding() {
        while (pc % 4 != 0) {
            readUint8();
        }
    }
    shared<i32[]> readInt32s(i32 n) {
        shared<i32[]> ints = std::make_unique<i32[]>(n);
        for (int i = 0; i < n; i++) {
            ints[i] = readInt32();
        }
        return ints;
    }
};