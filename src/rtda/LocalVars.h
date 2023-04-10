#include "../common/type.h"
#include "./Slot.h"

struct LocalVars {
    shared<Slot[]> slots;
    u32 maxLocal;
    LocalVars(u32 maxLocal);
    void setInt(u32 index, i32 val) { slots[index].num = val; }
    i32 getInt(u32 index) { return slots[index].num; }
    void setFloat(u32 index, float32 val) {
        slots[index].num = *reinterpret_cast<int*>(&val);
    }
    float32 getFloat(u32 index) {
        return *reinterpret_cast<float32*>(&slots[index].num);
    }
    void setLong(u32 index, i64 val) {
        slots[index].num = val & 0xFFFFFFFF;
        slots[index + 1].num = (u32) ((val >> 32) & 0xFFFFFFFF);
    }
    i64 getLong(u32 index) {
        i64 res = (u32) (slots[index].num);
        res |= ((u32) (slots[index + 1].num) * 1L) << 32;
        return res;
    }
    void setDouble(u32 index, float64 val) {
        setLong(index, *reinterpret_cast<i64*>(&val));
    }
    float64 getDouble(u32 index) {
        i64 bits = getLong(index);
        return *reinterpret_cast<float64*>(&bits);
    }
    void setRef(u32 index, Object* ref) {
        slots[index].ref = ref;
    }
    Object* getRef(u32 index) {
        return slots[index].ref;
    }
    string toString();
};

namespace localvars {
    shared<LocalVars> newLocalVars(u32 maxLocal);
};