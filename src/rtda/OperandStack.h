#pragma once

#include "../common/type.h"
#include "./Slot.h"
#include <memory>

struct OperandStack {
    u32 size;
    shared<Slot[]> slots;
    OperandStack(u32 maxStack) {
        slots = std::make_unique<Slot[]>(maxStack);
        size = 0;
    }
    void pushInt(i32 val) { slots[size++].num = val; }
    i32 popInt() { return slots[--size].num; }
    void pushFloat(float32 val) { 
        slots[size++].num = *reinterpret_cast<int*>(&val);
    }
    float32 popFloat() {
        return *reinterpret_cast<float32*>(&slots[--size].num);
    }
    void pushLong(i64 val) {
        slots[size].num = (u32) (val & 0xFFFFFFFF);
        slots[size + 1].num = (u32) ((val >> 32) & 0xFFFFFFFF);
        size += 2;
    }
    i64 popLong() {
        size -= 2;
        i64 res = (u32) slots[size].num;
        res |= ((u32) slots[size + 1].num * 1L) << 32;
        return res;
    }
    void pushDouble(float64 val) {
        pushLong(*reinterpret_cast<i64*>(&val));
    }
    float64 popDouble() {
        i64 val = popLong();
        return *reinterpret_cast<float64*>(&val);
    }
    void pushRef(heap::Object* ref) {
        slots[size++].ref = ref;
    }
    heap::Object* popRef() {
        heap::Object* ref = slots[--size].ref;
        slots[size].ref = nullptr;
        return ref;
    }
    void pushSlot(Slot slot) {
        slots[size++] = slot;
    }
    Slot popSlot() {
        return slots[--size];
    }
};

namespace operandstack {
    shared<OperandStack> newOperandStack(u32 maxStack);
}
