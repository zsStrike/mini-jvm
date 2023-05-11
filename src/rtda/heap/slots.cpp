//
// Created by strike on 5/10/23.
//

#include "slots.h"

namespace heap {
    Slots::Slots(u32 maxLocal) {
        this->maxLocal = maxLocal;
        slots = std::make_unique<Slot[]>(maxLocal);
    }

    string Slots::toString() {
        std::string str;
        for (int i = 0; i < maxLocal; i++) {
            str.append(std::to_string(slots[i].num)).append(" ");
        }
        return str;
    }

    shared<Slots> newSlots(u32 count) {
        auto slots = std::make_shared<Slots>(count);
        return slots;
    }
}
