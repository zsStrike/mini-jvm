#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "CompositeEntry.h"
#include "boost/filesystem.hpp"
#include "../log/log.h"

CompositeEntry::CompositeEntry(std::string pathList) {
    std::vector<std::string> tokens;
    boost::split(tokens, pathList, boost::is_any_of(":;"));
    for (auto& token : tokens) {
        entries.push_back(classpath::newEntry(token));
    }
}

std::shared_ptr<std::vector<byte>> CompositeEntry::readClass(std::string className) {
    for (auto& entry : entries) {
        auto bytes = entry->readClass(className);
        if (bytes != nullptr) {
            return bytes;
        }
    }
    return nullptr;
}

std::shared_ptr<std::string> CompositeEntry::toString() const {
    std::string str{};
    for (auto& entry : entries) {
        str.append(entry->toString()->c_str());
        str.append(", ");
    }
    return std::make_shared<std::string>(std::move(str));
} 