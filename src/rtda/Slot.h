#pragma once
#include "../common/type.h"
#include "heap/Object.h"

struct Slot {
    i32 num;
    heap::Object* ref;
};

