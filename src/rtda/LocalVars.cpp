#include "LocalVars.h"
#include <memory>

shared<LocalVars> localvars::newLocalVars(u32 maxLocal) {
    if (maxLocal > 0) {
        return make_shared<LocalVars>(maxLocal);
    }
    return nullptr;
}

LocalVars::LocalVars(u32 maxLocal) {
    slots = std::make_unique<Slot[]>(maxLocal);
}
