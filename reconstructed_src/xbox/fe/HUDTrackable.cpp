// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/HUDTrackable.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 11 functions matched (36.36%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_00 (0x001A2A60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTrackable::vfunc_00 (0x001A2A60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437204[];

class HUDTrackable
{
public:
    virtual void* vfunc_00();
};

void* HUDTrackable::vfunc_00()
{
    return DAT_00437204;
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_04 (0x001A2A70, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTrackable::vfunc_04 (0x001A2A70, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field84
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int, int, int);
};

extern "C" void __stdcall sub_00193190(int);

class HUDTrackable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
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
    virtual void vfunc_59(int);
    virtual void vfunc_60();
    char m_pad04[0x68];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    char m_pad74[0x4];
    int m_Field78; // +0x78
    char m_pad7C[0x8];
    Field84* m_Field84; // +0x84
    char m_pad88[0x10];
    int m_Field98; // +0x98
};

void HUDTrackable::vfunc_04(int a1)
{
    sub_00193190(a1);
    vfunc_29();
    vfunc_59(m_Field98);
    vfunc_60();
    m_Field84->vfunc_07(m_Field78, (int)(&m_Field6C), (int)(&m_Field70));
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_00 (0x001A30E0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDTrackable::vfunc_00 (0x001A30E0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int);
};

class HUDTrackable
{
public:
    virtual void vfunc_00(int a1, int a2);
    int m_Field04; // +0x04
    char m_pad08[0x18];
    int m_Field20; // +0x20
    char m_pad24[0x8];
    int m_Field2C; // +0x2C
};

void HUDTrackable::vfunc_00(int a1, int a2)
{
    int r_eax, t1;

    r_eax = a1;
    if (a1 == m_Field2C) {
        r_eax = *(int*)(a2 + 8);
        t1 = m_Field20;
        m_Field04 = r_eax;
        r_eax = ((Object*)t1)->vfunc_03(r_eax);
        *(unsigned char*)((char*)this - 0x4) |= 1;
    }
}

// ============================================================================
// [VERIFIED] HUDTrackable::vfunc_01 (0x001A32D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTrackable::vfunc_01 (0x001A32D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A2A10(void);
extern "C" void __cdecl sub_00027600(int);

class HUDTrackable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual HUDTrackable* vfunc_01(int a1);
};

HUDTrackable* HUDTrackable::vfunc_01(int a1)
{
    sub_001A2A10();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

