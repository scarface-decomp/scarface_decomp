// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DrivingRewardsObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DrivingRewardsObject::vfunc_05 (0x001E0120, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DrivingRewardsObject::vfunc_05 (Proto 0x001E0120, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field100
{
    void sub_000B57F0();
};

struct Field118
{
    void sub_000B5830();
};

struct FieldCC
{
    void sub_000B5810();
};

struct FieldE8
{
    void sub_001B7A10();
};

extern "C" void __stdcall sub_00028C40(int);

class DrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0xC8];
    FieldCC m_FieldCC; // +0xCC
    char m_padCD[0x1B];
    FieldE8 m_FieldE8; // +0xE8
    char m_padE9[0x17];
    Field100 m_Field100; // +0x100
    char m_pad101[0x17];
    Field118 m_Field118; // +0x118
    char m_pad119[0x17];
    Field118 m_Field130; // +0x130
    char m_pad131[0x17];
    Field118 m_Field148; // +0x148
};

void DrivingRewardsObject::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_FieldCC.sub_000B5810();
    m_FieldE8.sub_001B7A10();
    m_Field100.sub_000B57F0();
    m_Field118.sub_000B5830();
    m_Field130.sub_000B5830();
    m_Field148.sub_000B5830();
}

// ============================================================================
// [VERIFIED] DrivingRewardsObject::vfunc_00 (0x001E04C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DrivingRewardsObject::vfunc_00 (0x001E04C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426E38[];

class DrivingRewardsObject
{
public:
    virtual void* vfunc_00();
};

void* DrivingRewardsObject::vfunc_00()
{
    return DAT_00426E38;
}

// ============================================================================
// [VERIFIED] DrivingRewardsObject::vfunc_01 (0x001E0700, 91 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DrivingRewardsObject::vfunc_01 (Proto 0x001E0700, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_001B7A10();
};

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
    virtual void vfunc_28(int);
    int sub_0008D4E0(int);
};

extern "C" char DAT_003AA014[];
extern "C" Object DAT_00461EF4;
extern "C" int DAT_00461EF8;
extern "C" void __cdecl sub_00025160(int);

class DrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual DrivingRewardsObject* vfunc_01(int a1);
    void sub_000277E0();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
};

DrivingRewardsObject* DrivingRewardsObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003AA014;
    if (DAT_00461EF4.sub_0008D4E0(DAT_00461EF8)) {
        ((Object*)DAT_00461EF4.sub_0008D4E0(DAT_00461EF8))->vfunc_28((int)this);
    }
    m_Field30.sub_001B7A10();
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] DrivingRewardsObject::vfunc_27 (0x001E07A0, 54 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DrivingRewardsObject::vfunc_27 (Proto 0x001E07A0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    int sub_00026D50();
    int sub_000D53A0();
};

struct Object
{
    void sub_000B5F80(int, int);
};

extern "C" void __cdecl sub_001E06A0(int);

class DrivingRewardsObject
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
    virtual void vfunc_27(int a1);
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
};

void DrivingRewardsObject::vfunc_27(int a1)
{
    int t2;

    if (m_Field30.sub_00026D50()) {
        t2 = m_Field30.sub_000D53A0();
        sub_001E06A0(t2);
        ((Object*)t2)->sub_000B5F80(a1, (int)this);
    }
}

