//
// Created by strike on 4/11/23.
//

#include "class_loader.h"
#include "../../log/log.h"
#include "./constant_pool.h"

namespace heap {
    void calcInstanceFieldSlotIds(shared<Class> klass) {
        auto slotId = 0;
        if (klass->superClass != nullptr) {
            slotId = klass->superClass->instanceSlotCount;
        }
        int size = klass->fields->size();
        for (int i = 0; i < size; i++) {
            auto field = klass->fields->at(i);
            if (!field->isStatic()) {
                field->SlotId = slotId;
                slotId++;
                if (field->isLongOrDouble()) {
                    slotId++;
                }
            }
        }
        klass->instanceSlotCount = slotId;
    }

    void calcStaticFieldSlotIds(shared<Class> klass) {
        auto slotId = 0;
        int size = klass->fields->size();
        for (int i = 0; i < size; i++) {
            auto field = klass->fields->at(i);
            if (field->isStatic()) {
                field->SlotId = slotId;
                slotId++;
                if (field->isLongOrDouble()) {
                    slotId++;
                }
            }
        }
        klass->staticSlotCount = slotId;
    }



    void initStaticFinalVar(shared<Class> klass, shared<Field> field) {
        auto vars = klass->staticVars;
        auto cp = klass->constantPool;
        auto cpIndex = field->constValueIndex;
        auto slotId = field->SlotId;
        string i32Des = "ZBCSI";
        string i64Des = "J";
        string f32Des = "F";
        string f64Des = "D";
        string strDes = "Ljava/lang/String;";
        if (cpIndex > 0) {
            auto contant = cp->getConstant(cpIndex);
            string des = *field->descriptor;
            if (i32Des.find(des) != string::npos) {
                vars->setInt(slotId, std::static_pointer_cast<i32Constant>(contant)->val);
            } else if (i64Des.find(des) != string::npos) {
                vars->setLong(slotId, std::static_pointer_cast<i64Constant>(contant)->val);
            } else if (f32Des.find(des) != string::npos) {
                vars->setFloat(slotId, std::static_pointer_cast<f32Constant>(contant)->val);
            } else if (f64Des.find(des) != string::npos) {
                vars->setDouble(slotId, std::static_pointer_cast<f64Constant>(contant)->val);
            } else if (strDes.find(des) != string::npos) {
                LOG_INFO("panic: todo");
            }
        }
    }

    void allocAndInitStaticVars(shared<Class> klass) {
        klass->staticVars = std::make_shared<Slots>(klass->staticSlotCount);
        for (auto&& field : *klass->fields) {
            if (field->isStatic() && field->isFinal()) {
                initStaticFinalVar(klass, field);
            }
        }
    }

    void prepare(shared<Class> klass) {
        calcInstanceFieldSlotIds(klass);
        calcStaticFieldSlotIds(klass);
        allocAndInitStaticVars(klass);
    }

    void verify(shared<Class> klass) {
        // TODO
    }

    void link(shared<Class> klass) {
        verify(klass);
        prepare(klass);
    }

    shared<ClassLoader> newClassLoader(shared<Classpath> cp) {
        auto loader = std::make_shared<ClassLoader>();
        loader->cp = cp;
        loader->classMap = {};
        return loader;
    }


    shared<Class> ClassLoader::loadNonArrayClass(shared<string> name) {
        auto [data, entry] = readClass(name);
        LOG_INFO("loadNonArrayClass");
        auto klass = defineClass(data);
        link(klass);
        LOG_INFO("loaded %s from %s", *name, entry);
        return klass;
    }

    shared<Class> ClassLoader::loadClass(shared<string> name) {
        if (classMap.count(*name) == 1) {
            return classMap[*name];
        }
        return loadNonArrayClass(name);
    }

    tuple<shared_buffer, shared<Entry>> ClassLoader::readClass(shared<string> name) {
        auto data = cp->readClass(*name);
        return std::make_tuple(data, std::make_shared<Entry>());
    }

    shared<Class> parseClass(shared_buffer data) {
        auto cf = make_shared<ClassFile>();
        cf->parse(data);
        return newClass(cf);
    }





    void resolveSuperClass(shared<Class> klass) {
        LOG_INFO("resolveSuperClass")
        if (*klass->name == "java/lang/Object") {
            klass->superClass = klass->loader->loadClass(klass->superClassName);
        }
    }

    void resolveInterfaces(shared<Class> klass) {
        LOG_INFO("resolveInterfaces")
        auto count = klass->interfaceNames->size();
        if (count > 0) {
            klass->interfaces = make_shared<vs<Class>>(count);
            for (int i = 0; i < count; i++) {
                klass->interfaces->at(i) = klass->loader->loadClass(klass->interfaceNames->at(i));
            }
        }
    }

    shared<Class> ClassLoader::defineClass(shared_buffer data) {
        LOG_INFO("ClassLoader::defineClass")
        auto klass = parseClass(data);
        klass->loader = shared_from_this(); // TODO: std::make_shared_from_this
        resolveSuperClass(klass);
        resolveInterfaces(klass);
        this->classMap[*klass->name] = klass;
        return klass;
    }
}


