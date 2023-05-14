#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <zip.h>
#include "../common/type.h"
#include "ZipEntry.h"
#include "boost/filesystem.hpp"
#include "../log/log.h"

namespace bf = boost::filesystem;

ZipEntry::ZipEntry(std::string path) {
    absPath = bf::system_complete(path).c_str();
}

std::shared_ptr<std::vector<byte>> ZipEntry::readClass(std::string className) {
    // LOG_INFO("absPath = %1%, className = %2%", absPath, className);
    className = className.substr(0, className.find_last_of('.'));
    std::replace(className.begin(), className.end(), '.', '/');
    className += ".class";
    auto path = bf::path(absPath).append(className);
    struct zip* za = zip_open(absPath.c_str(), ZIP_RDONLY, nullptr);
    if (!za) {
        // LOG_INFO("error open zip file");
        return nullptr;
    }

    // find the index of the given file name within the zip archive
    zip_int64_t index = zip_name_locate(za, className.c_str(), 0);
    if (index < 0) {
        // LOG_INFO("error index the target");
        return nullptr;
    }

    // get the uncompressed size of the file
    struct zip_stat st;
    if (zip_stat_index(za, index, 0, &st) != 0) {
        // LOG_INFO("error stat index");
        return nullptr;
    }    

    std::shared_ptr<std::vector<byte>> bytes = std::make_shared<std::vector<byte>>(st.size);
    // LOG_INFO("size: %1%", bytes->size());

    zip_file_t *file = zip_fopen_index(za, index, 0);
    zip_fread(file, bytes->data(), st.size);
    LOG_INFO("className: %1%", className);
    zip_fclose(file);
    zip_close(za);

    return bytes;
}

std::shared_ptr<std::string> ZipEntry::toString() const {
    return std::make_shared<std::string>(absPath);
}
