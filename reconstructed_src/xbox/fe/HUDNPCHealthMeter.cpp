// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/HUDNPCHealthMeter.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 8 functions matched (25.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDNPCHealthMeter::vfunc_59 (0x00199AE0, 193 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDNPCHealthMeter::vfunc_59 (0x00199AE0, 193 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int);
    virtual void vfunc_11(int, int, int);
    virtual void vfunc_12(int, int);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34(int, int);
    virtual void vfunc_35();
    virtual void vfunc_36(int, int);
    int sub_0018EF70();
    void sub_001C6A10(int);
};

extern "C" char DAT_003A28A4[];
extern "C" char DAT_003BC0E8[];
extern "C" int __cdecl sub_00023EC0(int);
extern "C" int __cdecl sub_00027590(int);
extern "C" int __cdecl sub_0009A2B0(int, int, int);

class HUDNPCHealthMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    char m_pad04[0x64];
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x18];
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    int m_Field90; // +0x90
    int m_Field94; // +0x94
    char m_pad98[0x4];
    int m_Field9C; // +0x9C
    char m_padA0[0x18];
    int m_FieldB8; // +0xB8
    int m_FieldBC; // +0xBC
};

void HUDNPCHealthMeter::vfunc_59()
{
    int r_edi, t5;

    r_edi = sub_00023EC0(m_Field6C);
    if (r_edi) {
        ((Object*)r_edi)->vfunc_34((int)(&m_FieldB8), (int)(((char*)this + 0xBA)));
        ((Object*)r_edi)->vfunc_36((int)(&m_FieldBC), (int)(((char*)this + 0xBE)));
    }
    t5 = sub_00027590(44);
    if (t5) {
        r_edi = ((Object*)t5)->sub_0018EF70();
    } else {
        r_edi = 0;
    }
    ((Object*)r_edi)->vfunc_12(m_Field6C, sub_0009A2B0((int)DAT_003A28A4, m_Field9C, (int)DAT_003BC0E8));
    ((Object*)r_edi)->sub_001C6A10(1);
    ((Object*)r_edi)->vfunc_11(m_Field8C, m_Field90, m_Field94);
    ((Object*)r_edi)->vfunc_10(m_Field88);
    m_Field68 = r_edi;
}

// ============================================================================
// [VERIFIED] HUDNPCHealthMeter::vfunc_00 (0x0019A7D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns HUDNPCHealthMeter's static class record (ConcreteClassRep<HUDNPCHealthMeter>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDNPCHealthMeter::vfunc_00 (0x0019A7D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436BB4[];

class HUDNPCHealthMeter
{
public:
    virtual void* vfunc_00();
};

void* HUDNPCHealthMeter::vfunc_00()
{
    return DAT_00436BB4;
}

