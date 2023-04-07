#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "CompositeEntry.h"

struct WildcardEntry : CompositeEntry {
    WildcardEntry(std::string path);
};