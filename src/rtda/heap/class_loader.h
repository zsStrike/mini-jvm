#pragma once
#include "../../classpath/Classpath.h"
#include "class.h"

namespace heap {
    struct Class;
    struct ClassLoader : public std::enable_shared_from_this<ClassLoader> {
        shared<Classpath> cp;
        umap<string, shared<Class>> classMap;

        shared<Class> loadNonArrayClass(shared<string> name);
        shared<Class> loadClass(shared<string> name);
        tuple<shared_buffer, shared<Entry>> readClass(shared<string> name);
        shared<Class> defineClass(shared_buffer data);

    };

    shared<ClassLoader> newClassLoader(shared<Classpath> cp);
}