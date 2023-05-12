#include <boost/filesystem/convenience.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "WildcardEntry.h"
#include "boost/filesystem.hpp"
#include "../log/log.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

WildcardEntry::WildcardEntry(std::string path) {
//    LOG_INFO("className = %1% absDir = %2%", className, absDir);
    std::string baseDir = path.substr(0, path.length() - 2);
    // LOG_INFO("path is %1%, baseDir is %2%", path, baseDir);

    for (fs::directory_entry& entry : fs::recursive_directory_iterator(baseDir)) {
        const fs::path& current_path = entry.path();
        if (fs::is_directory(current_path) || current_path.parent_path().c_str() != baseDir) {
            continue;
        }
        if (fs::extension(current_path) == ".jar" || fs::extension(current_path) == ".JAR") {
            // LOG_INFO("loading %1%", current_path.c_str());
            entries.push_back(classpath::newEntry(current_path.c_str()));
        }
    }
}
