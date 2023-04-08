#pragma once
#include "../common/type.h"

struct ClassReader {
    shared_buffer data;
    u32 pos;
    ClassReader(shared_buffer _data) : data(_data), pos(0) {};
    u8 readUint8();
    u16 readUint16();
    u32 readUint32();
    u64 readUint64();
    shared_buffer readBytes(u32 length);
    shared_u16Buffer readUint16s();
};