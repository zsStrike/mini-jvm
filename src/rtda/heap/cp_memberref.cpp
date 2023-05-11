//
// Created by strike on 4/11/23.
//

#include "cp_memberref.h"

void heap::MemberRef::copyMemberRefInfo(shared<ConstantMemberrefInfo> refInfo) {
    className = refInfo->getClassName();
    auto&& [name_, descriptor_] = refInfo->getNameAndDescriptor();
    name = name_;
    descriptor  = descriptor_;
}

//bool heap::MemberRef::isAccessibleTo(shared<heap::Class> d) {
//    if (isPublic()) {
//        return true;
//    }
//    auto c = klass;
//    if (isProtected()) {
//        return d == c || d->isSubClassOf(c) || c->getPackageName() == d->getPackageName();
//    }
//    if (!isPrivate()) {
//        return c->getPackageName() == d->getPackageName();
//    }
//    return d == c;
//}

