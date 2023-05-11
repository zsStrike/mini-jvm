//
// Created by strike on 4/11/23.
//

#include "class_member.h"
#include "./access_flag.h"
#include "class.h"

namespace heap {
    void ClassMember::copyMemberInfo(shared<MemberInfo> memberInfo) {
        accessFlags = memberInfo->accessFlags;
        name = memberInfo->getName();
        descriptor = memberInfo->getDescriptor();
    }

    bool ClassMember::isPublic() {
        return (accessFlags & ACC_PUBLIC) != 0;
    }

    bool ClassMember::isPrivate() {
        return (accessFlags & ACC_PRIVATE) != 0;
    }

    bool ClassMember::isProtected() {
        return (accessFlags & ACC_PROTECTED) != 0;
    }

    bool ClassMember::isStatic() {
        return (accessFlags & ACC_STATIC) != 0;
    }

    bool ClassMember::isFinal() {
        return (accessFlags & ACC_FINAL) != 0;
    }

    bool ClassMember::isVolatile() {
        return (accessFlags & ACC_VOLATILE) != 0;
    }

    bool ClassMember::isTransient() {
        return (accessFlags & ACC_TRANSIENT) != 0;
    }

    bool ClassMember::isSynthetic() {
        return (accessFlags & ACC_SYNTHETIC) != 0;
    }

    bool ClassMember::isEnum() {
        return (accessFlags & ACC_ENUM) != 0;
    }

    bool ClassMember::isSynchronized() {
        return (accessFlags & ACC_SYNCHRONIZED) != 0;
    }

    bool ClassMember::isBridge() {
        return (accessFlags & ACC_BRIDGE) != 0;
    }

    bool ClassMember::isVarargs() {
        return (accessFlags & ACC_VARARGS) != 0;
    }

    bool ClassMember::isNative() {
        return (accessFlags & ACC_NATIVE) != 0;
    }

    bool ClassMember::isAbstract() {
        return (accessFlags & ACC_ABSTRACT) != 0;
    }

    bool ClassMember::isStrict() {
        return (accessFlags & ACC_STRICT) != 0;
    }

    bool ClassMember::isAccessibleTo(shared<Class> d) {
        if (isPublic()) return true;
        shared<Class> c = klass;
        if (isProtected()) {
            return d == c || d->isSubClassOf(c) || c->getPackageName() == d->getPackageName();
        }
        if (!isPrivate()) {
            return c->getPackageName() == d->getPackageName();
        }
        return d == c;
    }
}


