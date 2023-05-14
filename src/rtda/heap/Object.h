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
        virtual i32 getLen() {
            LOG_INFO("not implemented for pure Object");
            return -1;
        }

        void setRefVal(shared<string> name, shared<string> descriptor, Object* ref);
        Object* getRefVal(shared<string> name, shared<string> descriptor);
    };

    template<typename T>
    struct ArrayObject : Object {
        shared<T[]> data;
        i32 len;
        ArrayObject(uint count) {
            len = count;
            data = std::make_unique<T[]>(len);
        }
        shared<T[]> getData() { return data; }
        i32 getLen() override { return len; }
    };

    Object* newObject(shared<Class> klass);

    template<typename T>
    Object* newArray(shared<Class> klass, uint count) {
        Object* obj =  new ArrayObject<T>(count);
        obj->klass = klass;
        return obj;
    }

}




