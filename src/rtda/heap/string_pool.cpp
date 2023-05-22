//
// Created by strike on 5/13/23.
//
#include <string>
#include <codecvt>

#include "string_pool.h"

#include "../../common/type.h"

std::tuple<shared<char16_t[]>, int> string2char16s(shared<string> str) {
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
    auto wstr = convert.from_bytes(*str);
    int size = wstr.size();
    std::shared_ptr<char16_t[]> chars = std::make_unique<char16_t[]>(size);
    for (int i = 0; i < wstr.size(); i++) {
        chars[i] = wstr.at(i);
    }
    return std::make_tuple(chars, size);
}

heap::Object *heap::JString(shared<heap::ClassLoader> loader, shared<string> str) {
    if (internedStrings.count(*str) == 1) {
        return internedStrings[*str];
    }
    auto [chars, count] = string2char16s(str);
    auto jChars = new ArrayObject<char16_t>(count);
    jChars->klass = loader->loadClass(std::make_shared<string>("[C"));
    jChars->data = chars;
    auto jStr = loader->loadClass(make_shared<string>("java/lang/String"))->newObject();
    jStr->setRefVal(make_shared<string>("value"), make_shared<string>("[C"), jChars);
    internedStrings[*str] = jStr;
    return jStr;
}

shared<string> utf16ToString(shared<char16_t[]> chars, int count) {
    LOG_INFO("utf16ToString")
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
    auto res = make_shared<string>(converter.to_bytes(chars.get(), chars.get() + count));
    LOG_INFO("res: %s", *res)
    return res;
}

shared<string> heap::cppString(heap::Object *jStr) {
    LOG_INFO("cppString")
    auto charArr = jStr->getRefVal(make_shared<string>("value"), make_shared<string>("[C"));
    if (charArr == nullptr) {
        LOG_INFO("charArr is null")
    }
//    auto tmp = dynamic_cast<heap::ArrayObject<u16>*>(charArr);
//    if (tmp != nullptr) {
//        for (int i = 0; i < tmp->getLen(); i++) {
//            LOG_INFO("%d", tmp->getData()[i]);
//        }
//    }
    LOG_INFO("cppString, charArr type : %s", typeid(charArr).name());


    auto arrObj = dynamic_cast<heap::ArrayObject<char16_t>*>(charArr);
    if (arrObj != nullptr) {
        for (int i = 0; i < arrObj->getLen(); i++) {
            LOG_INFO("%d", arrObj->getData()[i]);
        }
    }
    LOG_INFO("cppString")
    LOG_INFO("cppString, len = %s", arrObj->getLen());

    return utf16ToString(arrObj->getData(), arrObj->getLen());
}

heap::Object *heap::internString(heap::Object *jStr) {
    auto cppStr = cppString(jStr);
    LOG_INFO("cppStr=%s", *cppStr)
    if (internedStrings.count(*cppStr) == 1) {
        return internedStrings[*cppStr];
    }
    internedStrings[*cppStr] = jStr;
    return jStr;
}
