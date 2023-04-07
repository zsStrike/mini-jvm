#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"
#include "Entry.h"

struct DirEntry : Entry {
    std::string absDir;
    DirEntry(std::string path);
    virtual std::shared_ptr<std::vector<byte>> readClass(std::string classPath) override;
    virtual std::shared_ptr<std::string> toString() const override;
};