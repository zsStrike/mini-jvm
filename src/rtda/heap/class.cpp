//
// Created by strike on 4/11/23.
//

#include "class.h"
#include "access_flag.h"
#include "Object.h"
#include "../../log/log.h"
#include "class_name_helper.h"

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
        LOG_INFO("newClass");

        klass->fields = newFields(klass, cf->fields);
        LOG_INFO("newClass");

        klass->methods = newMethods(klass, cf->methods);
        LOG_INFO("newClass");

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
        if (!s->isArray()) {
            if (!s->isInterface()) {
                if (!t->isInterface()) {
                    return s->isSubClassOf(t);
                } else {
                    return s->isImplements(t);
                }
            } else {
                if (!t->isInterface()) {
                    return t->isJlObject();
                } else {
                    return t->isSuperInterfaceOf(s);
                }
            }
        } else {
            if (!t->isArray()) {
                if (!t->isInterface()) {
                    return t->isJlObject();
                } else {
                    return t->isJlCloneable() || t->isJioSerializable();
                }
            } else {
                auto sc = s->componentClass();
                auto tc = t->componentClass();
                return sc == tc || tc->isAssignableFrom(sc);
            }
        }

        return false;
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
        LOG_INFO("method name = %s, descriptor = %s", *name, *descriptor);
        for (auto method : *methods) {
            if (method->isStatic() &&
                *method->name == *name &&
                *method->descriptor == *descriptor) {
                return method;
            }
        }
        return nullptr;
    }

    bool Class::isSuperClassOf(shared<Class> other) {
        return other->isSubClassOf(shared_from_this());
    }

    void Class::startInit() {
        initStarted = true;
    }

    shared<Method> Class::getClinitMethod() {
        return getStaticMethod(make_shared<string>("<clinit>"), make_shared<string>("()V"));
    }

    bool Class::isArray() {
        return name->at(0) == '[';
    }

    Object *Class::newArray(uint count) {
        if (!isArray()) {
            LOG_INFO("Not array class: %s", *name);
        }
        if (*name == "[Z") { return heap::newArray<i8>(shared_from_this(), count); }
        else if (*name == "[B") { return heap::newArray<i8>(shared_from_this(), count); }
        else if (*name == "[C") { return heap::newArray<u16>(shared_from_this(), count); }
        else if (*name == "[S") { return heap::newArray<i16>(shared_from_this(), count); }
        else if (*name == "[I") { return heap::newArray<i32>(shared_from_this(), count); }
        else if (*name == "[J") { return heap::newArray<i64>(shared_from_this(), count); }
        else if (*name == "[F") { return heap::newArray<float32>(shared_from_this(), count); }
        else if (*name == "[D") { return heap::newArray<float64>(shared_from_this(), count); }
        else { return heap::newArray<Object*>(shared_from_this(), count); }
    }

    shared<Class> Class::arrayClass() {
        auto arrayClassName = getArrayClassName(name);
        return loader->loadClass(arrayClassName);
    }

    shared<string> toClassName(shared<string> descriptor) {
        if (descriptor->at(0) == '[') { // array
            return descriptor;
        }
        if (descriptor->at(0) == 'L') { // Object
            return make_shared<string>(descriptor->begin() + 1, descriptor->end());
        }
        for (auto [className, d] : primitiveTypes) {
            if (d == *descriptor) {     // primitive
                return make_shared<string>(className);
            }
        }
        LOG_INFO("invalid descriptor: %s", *descriptor);
        return nullptr;
    }

    shared<string> getComponentClassName(shared<string> className) {
        if (className->at(0) == '[') {
            auto componentTypeDescriptor = make_shared<string>(className->begin() + 1, className->end());
            return toClassName(componentTypeDescriptor);
        }
        LOG_INFO("not array: %s", *className);
        return nullptr;
    }

    shared<Class> Class::componentClass() {
        auto componentClassName = getComponentClassName(name);
        return loader->loadClass(componentClassName);
    }

    bool Class::isSuperInterfaceOf(shared<Class> iface) {
        return iface->isSubInterfaceOf(shared_from_this());
    }

    bool Class::isJlObject() {
        return *name == "java/lang/Object";
    }

    bool Class::isJlCloneable() {
        return *name == "java/lang/Cloneable";
    }

    bool Class::isJioSerializable() {
        return *name == "java/io/Serializable";
    }

    shared<Field> Class::getField(shared<string> name, shared<string> descriptor, bool isStatic) {
        for (auto c = shared_from_this(); c != nullptr; c = c->superClass) {
            for (auto field : *c->fields) {
                if (field->isStatic() == isStatic &&
                    *field->name == *name &&
                    *field->descriptor == *descriptor) {
                    return field;
                }
            }
        }
        return nullptr;
    }
}


