//
// Created by strike on 5/12/23.
//

#include "class_name_helper.h"


namespace heap {



    shared<string> toDescriptor(shared<string> className) {
        if (className->at(0) == '[') {
            return className;
        }
        if (primitiveTypes.count(*className) == 1) {
            return make_shared<string>(primitiveTypes[*className]);
        }
        return make_shared<string>("L" + *className + ";");
    }



    shared<string> getArrayClassName(shared<string> className) {
        return make_shared<string>("[" + *toDescriptor(className));
    }

}


