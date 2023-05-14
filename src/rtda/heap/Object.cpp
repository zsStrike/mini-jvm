


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

    void Object::setRefVal(shared<string> name, shared<string> descriptor, Object *ref) {
        auto field = klass->getField(name, descriptor, false);
        this->fileds->setRef(field->SlotId, ref);
    }

    Object *Object::getRefVal(shared<string> name, shared<string> descriptor) {
        auto field = klass->getField(name, descriptor, false);
        auto slots = this->fileds;
        return slots->getRef(field->SlotId);
    }

}


