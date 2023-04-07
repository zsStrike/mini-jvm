#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "../common/type.h"
#include "Entry.h"
#include "Classpath.h"

struct CompositeEntry : Entry {
    CompositeEntry() = default;
    CompositeEntry(std::string pathList);
    std::vector<std::shared_ptr<Entry>> entries;
    virtual std::shared_ptr<std::vector<byte>> readClass(std::string classPath) override;
    virtual std::shared_ptr<std::string> toString() const override;
};

