#pragma once

#include "class.h"
#include "slots.h"
//#include "../LocalVars.h"


namespace heap {
    struct Slots;

    struct Object {
        shared<Class> klass;
        shared<Slots> fileds;

        bool isInstanceOf(shared<Class> clazz);
    };

    Object* newObject(shared<Class> klass);

}


