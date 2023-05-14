//
// Created by strike on 5/13/23.
//
#include <string>
#include <codecvt>

#include "string_pool.h"

#include "../../common/type.h"

std::tuple<shared<wchar_t[]>, int> string2wchars(shared<string> str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    auto wstr = converter.from_bytes(*str);
    int size = wstr.size();
    std::shared_ptr<wchar_t[]> chars = std::make_unique<wchar_t[]>(size);
    for (int i = 0; i < wstr.size(); i++) {
        chars[i] = wstr.at(i);
    }
    return std::make_tuple(chars, size);
}

heap::Object *heap::JString(shared<heap::ClassLoader> loader, shared<string> str) {
    if (internedStrings.count(*str) == 1) {
        return internedStrings[*str];
    }
    auto [chars, count] = string2wchars(str);
    auto jChars = new ArrayObject<wchar_t>(count);
    jChars->klass = loader->loadClass(std::make_shared<string>("[C"));
    jChars->data = chars;
    auto jStr = loader->loadClass(make_shared<string>("java/lang/String"))->newObject();
    jStr->setRefVal(make_shared<string>("value"), make_shared<string>("[C"), jChars);
    internedStrings[*str] = jStr;
    return jStr;
}

shared<string> utf16ToString(shared<wchar_t[]> chars, int count) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return make_shared<string>(converter.to_bytes(chars.get(), chars.get() + count));
}

shared<string> heap::cppString(heap::Object *jStr) {
    auto charArr = jStr->getRefVal(make_shared<string>("value"), make_shared<string>("[C"));
    auto arrObj = dynamic_cast<heap::ArrayObject<wchar_t>*>(charArr);
    return utf16ToString(arrObj->getData(), arrObj->getLen());
}
