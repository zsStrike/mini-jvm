#include <cstring>
#include <memory>
#include <cstdlib>
#include "ClassReader.h"

u8 ClassReader::readUint8() {
    u8 res = data->at(pos++);
    return res;
}

u16 ClassReader::readUint16() {
    u16 res = readUint8() << 8;
    res |= readUint8();
    return res;
}

u32 ClassReader::readUint32() {
    u32 res = readUint16() << 16;
    res |= readUint16();
    return res;    
}

u64 ClassReader::readUint64() {
    u64 res = (readUint32() * 1L) << 32;
    res |= readUint32();
    return res;
}

shared_buffer ClassReader::readBytes(u32 length) {
    shared_buffer buf = std::make_shared<Buffer>(length);
    memcpy(buf->data(), data->data() + pos, length);
    pos += length;
    return buf;
}

shared_u16Buffer ClassReader::readUint16s() {
    u16 size = readUint16();
    shared_u16Buffer buf = std::make_shared<U16Buffer>(size);
    for (int i = 0; i < size; i++) {
        buf->push_back(readUint16());
    }
    return buf;
}
