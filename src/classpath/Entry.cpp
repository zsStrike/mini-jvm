#include <ios>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "Entry.h"
#include "../log/log.h"
#include "boost/filesystem.hpp"

namespace bf = boost::filesystem;

std::shared_ptr<std::vector<byte>> Entry::getClassBytes(std::string path) {
    LOG_INFO("%1%", path);
    uintmax_t size = bf::file_size(path);
    auto bytes = std::make_shared<std::vector<byte>>(size);
    bf::ifstream in(path);
    in.readsome((char *)bytes->data(), size);
    return bytes;
}

std::ostream& operator<<(std::ostream& os, const Entry& obj) {
    os << obj.toString();
    return os;
}