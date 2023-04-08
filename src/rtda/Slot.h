#pragma once
#include "../common/type.h"
#include "Object.h"

struct Slot {
    i32 num;
    Object* ref;
};
