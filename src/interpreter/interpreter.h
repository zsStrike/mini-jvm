#include "../instructions/base/Instruction.h"
#include "../classfile/MemberInfo.h"

struct Interpreter {
    static void interpret(std::shared_ptr<heap::Method> method);
};