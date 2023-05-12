//
// Created by strike on 4/10/23.
//

#include "factory.h"
#include "constants/nop.h"
#include "constants/const.h"
#include "constants/ipush.h"
#include "loads/iload.h"
#include "loads/lload.h"
#include "loads/fload.h"
#include "loads/dload.h"
#include "loads/aload.h"
#include "stores/istore.h"
#include "stores/lstore.h"
#include "stores/fstore.h"
#include "stores/dstore.h"
#include "stores/astore.h"
#include "stack/pop.h"
#include "stack/dup.h"
#include "stack/swap.h"
#include "math/rem.h"
#include "math/sh.h"
#include "math/and.h"
#include "math/or.h"
#include "math/xor.h"
#include "math/iinc.h"
#include "math/i2x.h"
#include "math/l2x.h"
#include "math/f2x.h"
#include "math/d2x.h"
#include "comparisions/lcmp.h"
#include "comparisions/fcmp.h"
#include "comparisions/dcmp.h"
#include "comparisions/ifcond.h"
#include "comparisions/if_icmp.h"
#include "comparisions/if_acmp.h"
#include "control/goto.h"
#include "control/tableswitch.h"
#include "control/lookupswitch.h"
#include "extended/goto_w.h"
#include "math/add.h"
#include "math/sub.h"
#include "math/mul.h"
#include "math/div.h"
#include "math/neg.h"
#include "constants/ldc.h"
#include "references/getstatic.h"
#include "references/putstatic.h"
#include "references/getfield.h"
#include "references/putfield.h"
#include "references/new.h"
#include "references/instanceof.h"
#include "references/checkcast.h"
#include "references/invokespecial.h"
#include "references/invokevirtual.h"
#include "references/invokestatic.h"
#include "references/invokeinterface.h"
#include "control/return.h"

shared<Instruction> instructions::newInstruction(u8 opcode) {
    switch (opcode) {
        case 0x00:
            return make_shared<NOP>();
        case 0x01:
            return make_shared<ACONST_NULL>();
        case 0x02:
            return make_shared<ICONST_M1>();
        case 0x03:
            return make_shared<ICONST_0>();
        case 0x04:
            return make_shared<ICONST_1>();
        case 0x05:
            return make_shared<ICONST_2>();
        case 0x06:
            return make_shared<ICONST_3>();
        case 0x07:
            return make_shared<ICONST_4>();
        case 0x08:
            return make_shared<ICONST_5>();
        case 0x09:
            return make_shared<LCONST_0>();
        case 0x0a:
            return make_shared<LCONST_1>();
        case 0x0b:
            return make_shared<FCONST_0>();
        case 0x0c:
            return make_shared<FCONST_1>();
        case 0x0d:
            return make_shared<FCONST_2>();
        case 0x0e:
            return make_shared<DCONST_0>();
        case 0x0f:
            return make_shared<DCONST_1>();
        case 0x10:
            return make_shared<BIPUSH>();
        case 0x11:
            return make_shared<SIPUSH>();
        case 0x12:
            return make_shared<LDC>();
        case 0x13:
            return make_shared<LDC_W>();
        case 0x14:
            return make_shared<LDC2_W>();
//        case 0x15:
//            return NewLoad(false)
//        case 0x16:
//            return NewLoad(true)
//        case 0x17:
//            return NewLoad(false)
//        case 0x18:
//            return NewLoad(true)
//        case 0x19:
//            return NewLoad(false)
        case 0x1a:
            return make_shared<ILOAD_0>();
        case 0x1b:
            return make_shared<ILOAD_1>();
        case 0x1c:
            return make_shared<ILOAD_2>();
        case 0x1d:
            return make_shared<ILOAD_3>();
        case 0x1e:
            return make_shared<LLOAD_0>();
        case 0x1f:
            return make_shared<LLOAD_1>();
        case 0x20:
            return make_shared<LLOAD_2>();
        case 0x21:
            return make_shared<LLOAD_3>();
        case 0x22:
            return make_shared<FLOAD_0>();
        case 0x23:
            return make_shared<FLOAD_1>();
        case 0x24:
            return make_shared<FLOAD_2>();
        case 0x25:
            return make_shared<FLOAD_3>();
        case 0x26:
            return make_shared<DLOAD_0>();
        case 0x27:
            return make_shared<DLOAD_1>();
        case 0x28:
            return make_shared<DLOAD_2>();
        case 0x29:
            return make_shared<DLOAD_3>();
        case 0x2a:
            return make_shared<ALOAD_0>();
        case 0x2b:
            return make_shared<ALOAD_1>();
        case 0x2c:
            return make_shared<ALOAD_2>();
        case 0x2d:
            return make_shared<ALOAD_3>();
//        case 0x2e:
//            return iaload
//        case 0x2f:
//            return laload
//        case 0x30:
//            return faload
//        case 0x31:
//            return daload
//        case 0x32:
//            return aaload
//        case 0x33:
//            return baload
//        case 0x34:
//            return caload
//        case 0x35:
//            return saload
//        case 0x36:
//            return NewStore(false)
//        case 0x37:
//            return NewStore(true)
//        case 0x38:
//            return NewStore(false)
//        case 0x39:
//            return NewStore(true)
//        case 0x3a:
//            return NewStore(false)
        case 0x3b:
            return make_shared<ISTORE_0>();
        case 0x3c:
            return make_shared<ISTORE_1>();
        case 0x3d:
            return make_shared<ISTORE_2>();
        case 0x3e:
            return make_shared<ISTORE_3>();
        case 0x3f:
            return make_shared<LSTORE_0>();
        case 0x40:
            return make_shared<LSTORE_1>();
        case 0x41:
            return make_shared<LSTORE_2>();
        case 0x42:
            return make_shared<LSTORE_3>();
        case 0x43:
            return make_shared<FSTORE_0>();
        case 0x44:
            return make_shared<FSTORE_1>();
        case 0x45:
            return make_shared<FSTORE_2>();
        case 0x46:
            return make_shared<FSTORE_3>();
        case 0x47:
            return make_shared<DSTORE_0>();
        case 0x48:
            return make_shared<DSTORE_1>();
        case 0x49:
            return make_shared<DSTORE_2>();
        case 0x4a:
            return make_shared<DSTORE_3>();
        case 0x4b:
            return make_shared<ASTORE_0>();
        case 0x4c:
            return make_shared<ASTORE_1>();
        case 0x4d:
            return make_shared<ASTORE_2>();
        case 0x4e:
            return make_shared<ASTORE_3>();
        case 0x4f:
//            return iastore
//        case 0x50:
//            return lastore
//        case 0x51:
//            return fastore
//        case 0x52:
//            return dastore
//        case 0x53:
//            return aastore
//        case 0x54:
//            return bastore
//        case 0x55:
//            return castore
//        case 0x56:
//            return sastore
        case 0x57:
            return make_shared<POP>();
        case 0x58:
            return make_shared<POP2>();
        case 0x59:
            return make_shared<DUP>();
//        case 0x5a:
//            return dup_x1
//        case 0x5b:
//            return dup_x2
        case 0x5c:
            return make_shared<DUP2>();
//        case 0x5d:
//            return dup2_x1
//        case 0x5e:
//            return dup2_x2
        case 0x5f:
            return make_shared<SWAP>();
        case 0x60:
            return make_shared<IADD>();
        case 0x61:
            return make_shared<LADD>();
        case 0x62:
            return make_shared<FADD>();
        case 0x63:
            return make_shared<DADD>();
        case 0x64:
            return make_shared<ISUB>();
        case 0x65:
            return make_shared<LSUB>();
        case 0x66:
            return make_shared<FSUB>();
        case 0x67:
            return make_shared<DSUB>();
        case 0x68:
            return make_shared<IMUL>();
        case 0x69:
            return make_shared<LMUL>();
        case 0x6a:
            return make_shared<FMUL>();
        case 0x6b:
            return make_shared<DMUL>();
        case 0x6c:
            return make_shared<IDIV>();
        case 0x6d:
            return make_shared<LDIV>();
        case 0x6e:
            return make_shared<FDIV>();
        case 0x6f:
            return make_shared<DDIV>();
        case 0x70:
            return make_shared<IREM>();
        case 0x71:
            return make_shared<LREM>();
        case 0x72:
            return make_shared<FREM>();
        case 0x73:
            return make_shared<DREM>();
        case 0x74:
            return make_shared<INEG>();
        case 0x75:
            return make_shared<LNEG>();
        case 0x76:
            return make_shared<FNEG>();
        case 0x77:
            return make_shared<DNEG>();
        case 0x78:
            return make_shared<ISHL>();
        case 0x79:
            return make_shared<LSHL>();
        case 0x7a:
            return make_shared<ISHR>();
        case 0x7b:
            return make_shared<LSHR>();
        case 0x7c:
            return make_shared<IUSHR>();
        case 0x7d:
            return make_shared<LUSHR>();
        case 0x7e:
            return make_shared<IAND>();
        case 0x7f:
            return make_shared<LAND>();
        case 0x80:
            return make_shared<IOR>();
        case 0x81:
            return make_shared<LOR>();
        case 0x82:
            return make_shared<IXOR>();
        case 0x83:
            return make_shared<LXOR>();
        case 0x84:
            return make_shared<IINC>();
        case 0x85:
            return make_shared<I2L>();
        case 0x86:
            return make_shared<I2F>();
        case 0x87:
            return make_shared<I2D>();
        case 0x88:
            return make_shared<L2I>();
        case 0x89:
            return make_shared<L2F>();
        case 0x8a:
            return make_shared<L2D>();
        case 0x8b:
            return make_shared<F2I>();
        case 0x8c:
            return make_shared<F2L>();
        case 0x8d:
            return make_shared<F2D>();
        case 0x8e:
            return make_shared<D2I>();
        case 0x8f:
            return make_shared<D2L>();
        case 0x90:
            return make_shared<D2F>();
//        case 0x91:
//            return i2b
//        case 0x92:
//            return i2c
//        case 0x93:
//            return i2s
        case 0x94:
            return make_shared<LCMP>();
        case 0x95:
            return make_shared<FCMPL>();
        case 0x96:
            return make_shared<FCMPG>();
        case 0x97:
            return make_shared<DCMPL>();
        case 0x98:
            return make_shared<DCMPG>();
        case 0x99:
            return make_shared<IFEQ>();
        case 0x9a:
            return make_shared<IFNE>();
        case 0x9b:
            return make_shared<IFLT>();
        case 0x9c:
            return make_shared<IFGE>();
        case 0x9d:
            return make_shared<IFGT>();
        case 0x9e:
            return make_shared<IFLE>();
        case 0x9f:
            return make_shared<IF_ICMPEQ>();
        case 0xa0:
            return make_shared<IF_ICMPNE>();
        case 0xa1:
            return make_shared<IF_ICMPLT>();
        case 0xa2:
            return make_shared<IF_ICMPGE>();
        case 0xa3:
            return make_shared<IF_ICMPGT>();
        case 0xa4:
            return make_shared<IF_ICMPLE>();
        case 0xa5:
            return make_shared<IF_ACMPEQ>();
        case 0xa6:
            return make_shared<IF_ACMPNE>();
        case 0xa7:
            return make_shared<GOTO>();
//        case 0xa8:
//            return &JSR{}
//        case 0xa9:
//            return make_shared<RET>();
        case 0xaa:
            return make_shared<TABLE_SWITCH>();
        case 0xab:
            return make_shared<LOOKUP_SWITCH>();
        case 0xac:
            return make_shared<IRETURN>();
        case 0xad:
            return make_shared<LRETURN>();

        case 0xae:
            return make_shared<FRETURN>();
        case 0xaf:
            return make_shared<DRETURN>();
        case 0xb0:
            return make_shared<ARETURN>();
        case 0xb1:
            return make_shared<RETURN>();
        case 0xb2:
            return make_shared<GET_STATIC>();
        case 0xb3:
            return make_shared<PUT_STATIC>();
        case 0xb4:
            return make_shared<GET_FIELD>();
        case 0xb5:
            return make_shared<PUT_FIELD>();
        case 0xb6:
            return make_shared<INVOKE_VIRTUAL>();
        case 0xb7:
            return make_shared<INVOKE_SPECIAL>();
        case 0xb8:
            return make_shared<INVOKE_STATIC>();
        case 0xb9:
            return make_shared<INVOKE_INTERFACE>();
//        case 0xba:
//            return &InvokeDynamic{}
        case 0xbb:
            return make_shared<NEW>();
//        case 0xbc:
//            return &NewArray{}
//        case 0xbd:
//            return &ANewArray{}
//        case 0xbe:
//            return arraylength
//        case 0xbf:
//            return athrow
        case 0xc0:
            return make_shared<CHECK_CAST>();
        case 0xc1:
            return make_shared<INSTANCE_OF>();
//        case 0xc2:
//            return monitorenter
//        case 0xc3:
//            return monitorexit
//        case 0xc4:
//            return &Wide{}
//        case 0xc5:
//            return &MultiANewArray{}
//        case 0xc6:
//            return NewIfNull()
//        case 0xc7:
//            return NewIfNonNull()
        case 0xc8:
            return make_shared<GOTO_W>();
//        case 0xc9:
//            return &JSR_W{}
            //case 0xca: todo breakpoint
//        case 0xfe:
//            return invoke_native // impdep1
//        case 0xff:
//            return &Bootstrap{} // impdep2
        default:
            LOG_INFO("not implemneted for opcode: 0x%x", (uint)opcode);
            throw "not implemneted";
            return nullptr;
    }
}
