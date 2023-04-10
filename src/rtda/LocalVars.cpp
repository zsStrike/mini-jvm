#include "LocalVars.h"
#include <memory>

shared<LocalVars> localvars::newLocalVars(u32 maxLocal) {
    if (maxLocal > 0) {
        return make_shared<LocalVars>(maxLocal);
    }
    return nullptr;
}

LocalVars::LocalVars(u32 maxLocal) {
    this->maxLocal = maxLocal;
    slots = std::make_unique<Slot[]>(maxLocal);
}

string LocalVars::toString() {
    std::string str;
    for (int i = 0; i < maxLocal; i++) {
        str.append(std::to_string(slots[i].num)).append(" ");
    }
    return str;
}
