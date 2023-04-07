#pragma once
#include "Entry.h"

struct Classpath {
    std::shared_ptr<Entry> bootClasspath;
    std::shared_ptr<Entry> extClasspath;
    std::shared_ptr<Entry> userClasspath;
    void parse(std::string jrePath, std::string cpPath);
    void parseBootAndExtClasspath(std::string jrePath);
    void parseUserClasspath(std::string cpPath);
    std::shared_ptr<std::vector<byte>> readClass(std::string className);
};

namespace classpath {
    const std::string pathListSeparator(":");
    std::shared_ptr<Entry> newEntry(std::string path);
}