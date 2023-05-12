#pragma once

#include "method_descriptor.h"

namespace heap {
    struct MethodDescriptorParser {
        shared<string> raw;
        int offset;
        shared<MethodDescriptor> parsed;

        shared<MethodDescriptor> parse(shared<string> descriptor);
        void startParams();
        void endParams();
        void finish();
        void parseParamTypes();
        void parseReturnType();

        u8 readUint8();
        void unreadUint8();
        shared<string> parseFieldType();
        shared<string> parseObjectType();
        shared<string> parseArrayType();

        void badDescriptor();
    };
    shared<MethodDescriptor> parseMethodDescriptor(shared<string> descriptor);
}