#pragma once

#include "class.h"
#include "slots.h"
//#include "../LocalVars.h"


namespace heap {
    struct Slots;

    struct Object {
        shared<Class> klass;
        shared<Slots> fileds;
        shared<Class> extra; // for JClass

        bool isInstanceOf(shared<Class> clazz);
        virtual i32 getLen() {
            LOG_INFO("not implemented for pure Object");
            return -1;
        }

        void setRefVal(shared<string> name, shared<string> descriptor, Object* ref);
        Object* getRefVal(shared<string> name, shared<string> descriptor);
        virtual Object* clone();
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
        Object * clone() override;
    };

    template<typename T>
    Object *ArrayObject<T>::clone() {
        ArrayObject<T>* aobj = new ArrayObject<T>(this->getLen());
        for (int i = 0; i < this->getLen(); i++) {
            aobj->getData()[i] = this->getData()[i];
        }
        return aobj;
    }

    Object* newObject(shared<Class> klass);

    template<typename T>
    Object* newArray(shared<Class> klass, uint count) {
        Object* obj =  new ArrayObject<T>(count);
        obj->klass = klass;
        return obj;
    }

    void arrayCopy(Object* src, Object* dest, int srcPos, int dstPos, int length);

}




