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

        inline bool isPublic();
        inline bool isPrivate();
        inline bool isProtected();
        bool isStatic();
        bool isFinal();
        inline bool isSynchronized();
        inline bool isBridge();
        inline bool isVarargs();
        inline bool isNative();
        inline bool isAbstract();
        inline bool isStrict();
        inline bool isVolatile();
        inline bool isTransient();
        inline bool isSynthetic();
        inline bool isEnum();

        bool isAccessibleTo(shared<Class> klass);

        void copyMemberInfo(shared<MemberInfo> memberInfo);

    };
}
