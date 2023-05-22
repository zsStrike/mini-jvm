#pragma once
#include "../../classpath/Classpath.h"
#include "class.h"

namespace heap {
    struct Class;
    struct ClassLoader : public std::enable_shared_from_this<ClassLoader> {
        shared<Classpath> cp;
        umap<string, shared<Class>> classMap;
        bool verboseFlag;

        shared<Class> loadNonArrayClass(shared<string> name);
        shared<Class> loadClass(shared<string> name);
        tuple<shared_buffer, shared<Entry>> readClass(shared<string> name);
        shared<Class> defineClass(shared_buffer data);

        shared<Class> loadArrayClass(shared<string> name);
        void loadBasicClasses();
        void loadPrimitiveClass(shared<string> className);
        void loadPrimitiveClasses();
    };

    shared<ClassLoader> newClassLoader(shared<Classpath> cp, bool verboseFlag=false);
}