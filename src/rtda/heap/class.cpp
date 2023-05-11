//
// Created by strike on 4/11/23.
//

#include "class.h"
#include "access_flag.h"
#include "Object.h"
#include "../../log/log.h"

namespace heap {
    shared<Class> newClass(shared<ClassFile> cf) {
        LOG_INFO("newClass");
        auto klass = std::make_shared<Class>();
        klass->accessFlags = cf->accessFlags;
        klass->name = cf->getClassName();
        LOG_INFO("%s", *klass->name);

        klass->superClassName = cf->getSuperClassName();
        klass->interfaceNames = cf->getInterfaceNames();
        klass->constantPool = newConstantPool(klass, cf->constantPool);

        klass->fields = newFields(klass, cf->fields);
        klass->methods = newMethods(klass, cf->methods);
        return klass;
    }

    bool Class::isPublic() {
        return (accessFlags & ACC_PUBLIC) != 0;
    }

    bool Class::isFinal() {
        return (accessFlags & ACC_FINAL) != 0;
    }

    bool Class::isSuper() {
        return (accessFlags & ACC_SUPER) != 0;
    }

    bool Class::isInterface() {
        return (accessFlags & ACC_INTERFACE) != 0;
    }

    bool Class::isAbstract() {
        return (accessFlags & ACC_ABSTRACT) != 0;
    }

    bool Class::isSynthetic() {
        return (accessFlags & ACC_SYNTHETIC) != 0;
    }

    bool Class::isAnnotation() {
        return (accessFlags & ACC_ANNOTATION) != 0;
    }

    bool Class::isEnum() {
        return (accessFlags & ACC_ENUM) != 0;
    }

    bool Class::isAccessibleTo(shared<Class> other) {
        return isPublic() || getPackageName() == other->getPackageName();
    }

    string Class::getPackageName() {
        int idx = name->find_last_of("/");
        if (idx >= 0) {
            return name->substr(0, idx);
        }
        return "";
    }

    bool Class::isSubClassOf(shared<Class> other) {
        auto klass = superClass;
        while (klass != nullptr) {
            if (klass == other) return true;
            klass = klass->superClass;
        }
        return false;
    }



    Object *Class::newObject() {
        return heap::newObject(shared_from_this());
    }

    bool Class::isAssignableFrom(shared<Class> other) {
        auto s = other;
        auto t = shared_from_this();
        if (s == t) {
            return true;
        }
        if (!t->isInterface()) {
            return s->isSubClassOf(t);
        } else {
            return s->isImplements(t);
        }
    }

    bool Class::isImplements(shared<Class> iface) {
        for (auto c = shared_from_this(); c != nullptr; c = c->superClass) {
            for (auto i : *c->interfaces) {
                if (i == iface || i->isSubInterfaceOf(iface)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Class::isSubInterfaceOf(shared<Class> iface) {
        for (auto superInterface : *interfaces) {
            if (superInterface == iface || superInterface->isSubInterfaceOf(iface)) {
                return true;
            }
        }
        return false;
    }

    shared<Method> Class::getMainMethod() {
        auto name = make_shared<string>("main");
        auto descriptor = make_shared<string>("([Ljava/lang/String;)V");
        return getStaticMethod(name, descriptor);
    }

    shared<Method> Class::getStaticMethod(std::shared_ptr<string> name, std::shared_ptr<string> descriptor) {
        for (auto method : *methods) {
            LOG_INFO("method name = %s, descriptor = %s", *method->name, *method->descriptor);
            if (method->isStatic() &&
                *method->name == *name &&
                *method->descriptor == *descriptor) {
                return method;
            }
        }
        return nullptr;
    }
}


