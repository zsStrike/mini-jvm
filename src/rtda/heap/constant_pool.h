#pragma once
#include <utility>

#include "class.h"
#include "../../classfile/ConstantPool.h"
#include "cp_classref.h"
#include "cp_fieldref.h"
#include "cp_interface_methodref.h"
#include "cp_memthodref.h"

namespace heap {

    struct Constant {
        virtual shared<string> toString();
    };
    struct LiteralConstant : Constant {};
    struct SymRefConstant : Constant {};

    struct i32Constant : LiteralConstant {
        i32 val;
        explicit i32Constant(i32 val_) : val(val_) {};
    };
    struct f32Constant : LiteralConstant {
        float32 val;
        explicit f32Constant(float32 val_) : val(val_) {};
    };
    struct i64Constant : LiteralConstant {
        i64 val;
        explicit i64Constant(i64 val_) : val(val_) {};
    };
    struct f64Constant : LiteralConstant {
        float64 val;
        explicit f64Constant(float64 val_) : val(val_) {};
    };
    struct stringConstant : LiteralConstant {
        shared<string> val;
        explicit stringConstant(shared<string> val_) : val(val_) {};
    };

    struct ClassRef;
    struct ClassRefConstant : SymRefConstant {
        shared<ClassRef> val;
        explicit ClassRefConstant(shared<ClassRef> val_) : val(val_) {};
    };
    struct FieldRef;
    struct FieldRefConstant : SymRefConstant {
        shared<FieldRef> val;
        explicit FieldRefConstant(shared<FieldRef> val_) : val(val_) {};
    };
    struct MethodRef;
    struct MethodRefConstant : SymRefConstant {
        shared<MethodRef> val;
        explicit MethodRefConstant(shared<MethodRef> val_) : val(val_) {};
    };
    struct InterfaceMethodRef;
    struct InterfaceMethodRefConstant : SymRefConstant {
        shared<InterfaceMethodRef> val;
        explicit InterfaceMethodRefConstant(shared<InterfaceMethodRef> val_) : val(val_) {};
    };



//    union Constant {
//        i32 intergerVal;
//        i64 longVal;
//        float32 floatVal;
//        float64 doubleVal;
//        shared<string> stringVal;
//        shared<ClassRef> classRefVal;
//        shared<FieldRef> fieldRefVal;
//        shared<Method> methodRefVal;
//        shared<InterfaceMethodRef> interfaceMethodRefVal;
//        explicit Constant(i32 val) : intergerVal(val) {};
//        explicit Constant(i64 val) : longVal(val) {};
//        explicit Constant(float32 val) : floatVal(val) {};
//        explicit Constant(float64 val) : doubleVal(val) {};
//        explicit Constant(shared<string> str_) : stringVal(std::move(str_)) {};
//        explicit Constant(shared<ClassRef> ref) : classRefVal(std::move(ref)) {};
//        explicit Constant(shared<FieldRef> ref) : fieldRefVal(std::move(ref)) {};
//        explicit Constant(shared<Method> ref) : methodRefVal(std::move(ref)) {};
//        explicit Constant(shared<InterfaceMethodRef> ref) : interfaceMethodRefVal(std::move(ref)) {};
//        ~Constant() {
//            stringVal = nullptr;
//            classRefVal = nullptr;
//            fieldRefVal = nullptr;
//            methodRefVal = nullptr;
//            interfaceMethodRefVal = nullptr;
//        }
//    };

    struct ConstantPool {
        shared<Class> klass;
        svs<Constant> consts;
        shared<Constant> getConstant(uint index);
    };

    shared<ConstantPool> newConstantPool(shared<Class> klass, shared<::ConstantPool> cfCp);

}