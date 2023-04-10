#include "../instructions/base/Instruction.h"
#include "../classfile/MemberInfo.h"

struct Interpreter {
    static void interpret(shared<MemberInfo> memberInfo);
};