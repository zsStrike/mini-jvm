#pragma once
#include "cp_memthodref.h"

namespace heap {
    shared<Method> lookupMethodInClass(shared<Class> klass, shared<string> name, shared<string> descriptor);
    shared<Method> lookupMethodInInterfaces(svs<Class> ifaces, shared<string> name, shared<string> descriptor);
}