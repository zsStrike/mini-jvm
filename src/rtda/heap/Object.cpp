


#include "Object.h"
#include "slots.h"

#include <boost/type_index.hpp>

namespace heap {
    Object *newObject(shared<Class> klass) {
        Object* obj = new Object();
        obj->klass = klass;
        obj->fileds = newSlots(klass->instanceSlotCount);
        return obj;
    }

    template<typename T>
    void _arrayCopy(ArrayObject<T>* src, ArrayObject<T>* dst, int srcPos, int dstPos, int length) {
        LOG_INFO("_arrayCopy: type = %s", typeid(T).name())
        LOG_INFO("src.length = %d, dst.length=%d", src->getLen(), dst->getLen())
        for (int i = 0; i < src->getLen(); i++) {
            LOG_INFO("src[i] = %d", src->getData()[i])
        }
        for (int i = 0; i < length; i++) {
            LOG_INFO("data[%d]=%d", i + srcPos, src->getData()[i + srcPos]);
            dst->getData()[i + dstPos] = src->getData()[i + srcPos];
        }
    }

    void arrayCopy(Object *src, Object *dest, int srcPos, int dstPos, int length) {
        LOG_INFO("arraycopy for: %s", typeid(*src).name());
        LOG_INFO("arraycopy for: %s", typeid(ArrayObject<Object*>).name());
        LOG_INFO("arraycopy for: %s", boost::typeindex::type_id<ArrayObject<Object*>>().pretty_name());
        LOG_INFO("arraycopy for: %s", boost::typeindex::type_id_runtime(*src).pretty_name());
        LOG_INFO("arraycopy for: %s", boost::typeindex::type_id_runtime(*dest).pretty_name());
        if (typeid(*src) == typeid(ArrayObject<i32>)) {
            auto _src = dynamic_cast<ArrayObject<i32>*>(src);
            auto _dst = dynamic_cast<ArrayObject<i32>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<Object*>*)) {
            LOG_INFO("Object*")
            auto _src = dynamic_cast<ArrayObject<Object*>*>(src);
            auto _dst = dynamic_cast<ArrayObject<Object*>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<i8>)) {
            auto _src = dynamic_cast<ArrayObject<i8>*>(src);
            auto _dst = dynamic_cast<ArrayObject<i8>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<i16>)) {
            auto _src = dynamic_cast<ArrayObject<i16>*>(src);
            auto _dst = dynamic_cast<ArrayObject<i16>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<u16>)) {
            LOG_INFO("u16 type")
            auto _src = dynamic_cast<ArrayObject<u16>*>(src);
            auto _dst = dynamic_cast<ArrayObject<u16>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<char16_t>)) {
            LOG_INFO("char16_t type")

            auto _src = dynamic_cast<ArrayObject<char16_t>*>(src);
            auto _dst = dynamic_cast<ArrayObject<char16_t>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<i64>)) {
            auto _src = dynamic_cast<ArrayObject<i64>*>(src);
            auto _dst = dynamic_cast<ArrayObject<i64>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<float32>)) {
            auto _src = dynamic_cast<ArrayObject<float32>*>(src);
            auto _dst = dynamic_cast<ArrayObject<float32>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else if (typeid(*src) == typeid(ArrayObject<float64>)) {
            auto _src = dynamic_cast<ArrayObject<float64>*>(src);
            auto _dst = dynamic_cast<ArrayObject<float64>*>(dest);
            _arrayCopy(_src, _dst, srcPos, dstPos, length);
        } else {
            LOG_INFO("bad array for : %s", typeid(*src).name());
        }
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

    Object *Object::clone() {
        Object* obj = new Object();
        obj->klass = klass;
        obj->fileds = std::make_shared<Slots>(this->fileds->maxLocal);
        for (int i = 0; i < this->fileds->maxLocal; i++) {
            obj->fileds->slots[i] = this->fileds->slots[i];
        }
        return obj;
    }

}


