#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "../common/type.h"

struct Entry {
    virtual std::shared_ptr<std::vector<byte>> readClass(std::string classPath) {
        return nullptr;
    };
    virtual std::shared_ptr<std::string> toString() const {
        return std::make_shared<std::string>("default class entry");
    }
    std::shared_ptr<std::vector<byte>> getClassBytes(std::string path);
    friend std::ostream& operator<<(std::ostream& os, const Entry& obj);
};