#pragma once

#include "../../common/type.h"

namespace heap {

    inline umap<string, string> primitiveTypes {
            {"void", "V"},
            {"boolean", "Z"},
            {"byte", "B"},
            {"short", "S"},
            {"int", "I"},
            {"long", "J"},
            {"char", "C"},
            {"float", "F"},
            {"double", "D"},
    };

    shared<string> getArrayClassName(shared<string> className);
}