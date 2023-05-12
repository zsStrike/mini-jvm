#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "DirEntry.h"
#include "boost/filesystem.hpp"
#include "../log/log.h"

namespace bf = boost::filesystem;

DirEntry::DirEntry(std::string path) {
    absDir = bf::system_complete(path).c_str();
}

std::shared_ptr<std::vector<byte>> DirEntry::readClass(std::string className) {
    LOG_INFO("className = %1% absDir = %2%", className, absDir);
    bf::path fileName(absDir);
    fileName.append(className);
    bf::fstream istream(fileName);
    return getClassBytes(fileName.c_str());
}

std::shared_ptr<std::string> DirEntry::toString() const {
    return std::make_shared<std::string>(absDir);
}