


#include "Object.h"
#include "slots.h"

namespace heap {
    Object *newObject(shared<Class> klass) {
        Object* obj = new Object();
        obj->klass = klass;
        obj->fileds = newSlots(klass->instanceSlotCount);
        return obj;
    }

    bool Object::isInstanceOf(shared<Class> klass) {
        return klass->isAssignableFrom(this->klass);
    }
}


