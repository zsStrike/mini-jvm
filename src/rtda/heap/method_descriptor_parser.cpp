//
// Created by strike on 5/11/23.
//

#include "method_descriptor_parser.h"
#include "../../log/log.h"

namespace heap {

    shared<MethodDescriptor> parseMethodDescriptor(shared<string> descriptor) {
        auto parser = make_shared<MethodDescriptorParser>();
        return parser->parse(descriptor);
    }

    shared<MethodDescriptor> MethodDescriptorParser::parse(shared<string> descriptor) {
        raw = descriptor;
        parsed = make_shared<MethodDescriptor>();
        startParams();
        parseParamTypes();
        endParams();
        parseReturnType();
        finish();
        return parsed;
    }

    void MethodDescriptorParser::startParams() {
        if (readUint8() != '(') {
            badDescriptor();
        }
    }



    u8 MethodDescriptorParser::readUint8() {
        auto b = raw->at(offset);
        offset++;
        return b;
    }

    void MethodDescriptorParser::unreadUint8() {
        offset--;
    }

    void MethodDescriptorParser::badDescriptor() {
        LOG_INFO("badDescriptor = %s", *raw);
        throw "badDescriptor";
    }

    void MethodDescriptorParser::endParams() {
        if (readUint8() != ')') {
            badDescriptor();
        }
    }

    void MethodDescriptorParser::finish() {
        if (offset != raw->size()) {
            badDescriptor();
        }
    }

    void MethodDescriptorParser::parseParamTypes() {
        auto t = parseFieldType();
        while (t != nullptr) {
            parsed->addParameterType(t);
            t = parseFieldType();
        }
    }

    shared<string> MethodDescriptorParser::parseFieldType() {
        switch (readUint8()) {
            case 'B': return make_shared<string>("B");
            case 'C': return make_shared<string>("C");
            case 'D': return make_shared<string>("D");
            case 'F': return make_shared<string>("F");
            case 'I': return make_shared<string>("I");
            case 'J': return make_shared<string>("J");
            case 'S': return make_shared<string>("S");
            case 'Z': return make_shared<string>("Z");
            case 'L': return parseObjectType();
            case '[': return parseArrayType();
            default: unreadUint8(); return nullptr;
        }
    }

    shared<string> MethodDescriptorParser::parseObjectType() {
        LOG_INFO("parseObjectType");
        auto unread = make_shared<string>(raw->substr(offset));
        auto semicolonIndex = unread->find(';');
        if (semicolonIndex == string::npos) {
            badDescriptor();
            return nullptr;
        } else {
            auto objStart = offset - 1;
            auto objEnd = offset + semicolonIndex + 1;
            offset = objEnd;
            auto type = make_shared<string>(raw->substr(objStart, objEnd - objStart));
            LOG_INFO("type= %s", *type);
            return type;
        }

    }

    shared<string> MethodDescriptorParser::parseArrayType() {
        auto arrStart = offset - 1;
        parseFieldType();
        auto arrEnd = offset;
        auto type = make_shared<string>(arrStart, arrEnd - arrStart);
        return type;
    }

    void MethodDescriptorParser::parseReturnType() {
        if (readUint8() == 'V') {
            parsed->returnType = make_shared<string>("V");
            return;
        }
        unreadUint8();
        auto t = parseFieldType();
        if (t != nullptr) {
            parsed->returnType = t;
            return;
        }
        badDescriptor();
    }


}
