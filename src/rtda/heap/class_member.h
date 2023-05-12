#pragma once
#include "../../common/type.h"
#include "../../classfile/MemberInfo.h"

//#include "class.h"


namespace heap {
    struct Class;
    struct ClassMember {
        u16 accessFlags;
        shared<string> name;
        shared<string> descriptor;
        shared<Class> klass;

        bool isPublic();
        bool isPrivate();
        bool isProtected();
        bool isStatic();
        bool isFinal();
        bool isSynchronized();
        bool isBridge();
        bool isVarargs();
        bool isNative();
        bool isAbstract();
        bool isStrict();
        bool isVolatile();
        bool isTransient();
        bool isSynthetic();
        bool isEnum();

        bool isAccessibleTo(shared<Class> klass);

        void copyMemberInfo(shared<MemberInfo> memberInfo);

    };
}
