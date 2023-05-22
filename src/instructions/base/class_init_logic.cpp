//
// Created by strike on 5/12/23.
//

#include "class_init_logic.h"

void scheduleClinit(shared<Thread> thread, shared<heap::Class> klass) {
    auto clinit = klass->getClinitMethod();
    if (clinit != nullptr && clinit->klass == klass) {
        auto newFrame = thread->newFrame(clinit);
        thread->pushFrame(newFrame);
    }
}

void initSuperClass(shared<Thread> thread, shared<heap::Class> klass) {
    if (!klass->isInterface()) {
        auto superClass = klass->superClass;
        if (superClass != nullptr && !superClass->initStarted) {
            initClass(thread, superClass);
        }
    }
}

void initClass(shared<Thread> thread, shared<heap::Class> klass) {
    klass->startInit();
    scheduleClinit(thread, klass);
    initSuperClass(thread, klass);
}
