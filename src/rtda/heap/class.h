#pragma once

#include "../../common/type.h"
#include "../../classfile/ClassFile.h"

#include "class_loader.h"
#include "constant_pool.h"

#include "slots.h"
#include "field.h"
#include "method.h"
#include "Object.h"


namespace heap {
    struct Object;
    struct ClassLoader;
    struct ConstantPool;
    struct Class : public std::enable_shared_from_this<Class> {
        u16 accessFlags;
        shared<string> name;
        shared<string> superClassName;
        svs<string> interfaceNames;
        shared<ConstantPool> constantPool;
        svs<Field> fields;
        svs<Method> methods;
        shared<ClassLoader> loader;
        shared<Class> superClass;
        svs<Class> interfaces;
        uint instanceSlotCount;
        uint staticSlotCount;
        shared<Slots> staticVars;
        bool initStarted;

        bool isPublic();
        bool isFinal();
        bool isSuper();
        bool isInterface();
        bool isAbstract();
        bool isSynthetic();
        bool isAnnotation();
        bool isEnum();
        bool isArray();
        bool isJlObject();
        bool isJlCloneable();
        bool isJioSerializable();

        bool isAccessibleTo(shared<Class> other);
        string getPackageName();
        bool isSubClassOf(shared<Class> other);
        bool isSuperClassOf(shared<Class> other);
        bool isImplements(shared<Class> iface);
        bool isAssignableFrom(shared<Class> other);
        bool isSubInterfaceOf(shared<Class> iface);
        bool isSuperInterfaceOf(shared<Class> iface);


        void startInit();
        shared<Method> getClinitMethod();
        Object* newObject();

        Object* newArray(uint count);
        shared<Class> componentClass();

        shared<Method> getMainMethod();
        shared<Class> arrayClass();

        shared<Method> getStaticMethod(std::shared_ptr<string> name, std::shared_ptr<string> descriptor);
        shared<Field> getField(shared<string> name, shared<string> descriptor, bool isStatic);
    };

    shared<Class> newClass(shared<ClassFile> cf);
}
