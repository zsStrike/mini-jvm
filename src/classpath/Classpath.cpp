#include "Classpath.h"
#include "boost/filesystem.hpp"
#include "WildcardEntry.h"
#include "DirEntry.h"
#include "CompositeEntry.h"
#include "ZipEntry.h"
#include "../log/log.h"

namespace bf = boost::filesystem;

void Classpath::parseUserClasspath(std::string cpPath) {
    if (cpPath.size() == 0) {
        cpPath.append(".");
    }
    userClasspath = classpath::newEntry(cpPath);
}

std::shared_ptr<std::vector<byte>> Classpath::readClass(std::string className) {
    className += ".class";
    LOG_INFO("className=%1%", className);
    std::shared_ptr<std::vector<byte>> bytes = nullptr;
    if (bytes = bootClasspath->readClass(className); bytes != nullptr) {
        return bytes;
    }
    if (bytes = extClasspath->readClass(className); bytes != nullptr) {
        return bytes;
    }    
    return userClasspath->readClass(className);
}

std::string getJreDir(std::string jrePath) {
    if (jrePath.size() > 0 && bf::exists(jrePath)) {
        return jrePath;
    }
    if (bf::exists("./jre")) {
        return "./jre";
    }
    throw "bad jrePath";
}

void Classpath::parse(std::string jrePath, std::string cpPath) {
    parseBootAndExtClasspath(jrePath);
    parseUserClasspath(cpPath);
}

void Classpath::parseBootAndExtClasspath(std::string jrePath) {
  std::string jreDir = getJreDir(jrePath);
  std::string bootpath = bf::path(jreDir).append("lib").append("*").c_str();
  std::string extpath = bf::path(jreDir).append("lib").append("ext").append("*").c_str();
  bootClasspath = classpath::newEntry(bootpath);
  extClasspath = classpath::newEntry(extpath);
}

std::shared_ptr<Entry> classpath::newEntry(std::string path) {
    LOG_INFO("path is %1%", path);
    if (path.find(classpath::pathListSeparator) != std::string::npos) {
        return std::make_shared<CompositeEntry>(path);
    }
    if (path.find("*") == path.size() - 1) {
        return std::make_shared<WildcardEntry>(path);
    }
    if (path.find(".jar") == path.size() - 4 ||
        path.find(".zip") == path.size() - 4) {
            return std::make_shared<ZipEntry>(path);
        }

    return std::make_shared<DirEntry>(path);
}