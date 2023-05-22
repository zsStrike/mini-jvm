#pragma once

#include "Object.h"

namespace heap {
    inline umap<string, Object*> internedStrings = {};
    Object* JString(shared<ClassLoader> loader, shared<string> str);
    shared<string> cppString(Object* jStr);
    Object* internString(Object* jStr);
}