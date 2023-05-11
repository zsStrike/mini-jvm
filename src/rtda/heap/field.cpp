#include "field.h"
#include "./access_flag.h"

namespace heap {
    svs<Field> newFields(shared<Class> klass, svs<MemberInfo> cfFields) {
        auto size = cfFields->size();
        auto fields = std::make_shared<vs<Field>>(size);
        for (int i = 0; i < size; i++) {
            auto field = make_shared<Field>();
            field->klass = klass;
            field->copyMemberInfo(cfFields->at(i));
            field->copyAttributes(cfFields->at(i));
            fields->at(i) = field;
        }
        return fields;
    }

    bool Field::isLongOrDouble() {
        return *this->descriptor == "J" || *this->descriptor == "D";
    }

    void Field::copyAttributes(shared<MemberInfo> cfFields) {
        auto varAttr = cfFields->getConstantValueAttribute();
        if (varAttr != nullptr) {
            constValueIndex = uint(varAttr->constantValueIndex);
        }
    }
}


