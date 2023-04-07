#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "Entry.h"

struct ZipEntry : Entry {
    ZipEntry(std::string path);
    std::string absPath;
    virtual std::shared_ptr<std::vector<byte>> readClass(std::string classPath) override;
    virtual std::shared_ptr<std::string> toString() const override;
};