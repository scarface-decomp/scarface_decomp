// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MortarObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarObject::vfunc_00 (0x001EC7C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarObject::vfunc_00 (0x001EC7C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043E4C8[];

class MortarObject
{
public:
    virtual void* vfunc_00();
};

void* MortarObject::vfunc_00()
{
    return DAT_0043E4C8;
}

// ============================================================================
// [VERIFIED] MortarObject::vfunc_01 (0x001EC930, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarObject::vfunc_01 (0x001EC930, 72 bytes)
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
    virtual void vfunc_30(int);
    int sub_00098BB0(int);
};

extern "C" char DAT_003C9244[];
extern "C" char DAT_003C9264[];
extern "C" Object DAT_00491EA0;
extern "C" int DAT_00491EA4;
extern "C" void __cdecl sub_00027600(int);

class MortarObject
{
public:
    virtual void vfunc_00();
    virtual MortarObject* vfunc_01(int a1);
    void sub_001F0930();
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
};

MortarObject* MortarObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C9264;
    m_FieldA8 = (int)DAT_003C9244;
    ((Object*)DAT_00491EA0.sub_00098BB0(DAT_00491EA4))->vfunc_30((int)this);
    sub_001F0930();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] MortarObject::vfunc_32 (0x001F1420, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MeleeWeaponStateProp::vfunc_30 (0x001F13F0), which was matched first;
// its addresses and names were swapped for this function's.
// MortarObject::vfunc_32 (0x001F1420, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldC8
{
    void sub_00089050(int);
};

extern "C" void __stdcall sub_00029540(int);

class MortarObject
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
    virtual void vfunc_32(int a1);
    char m_pad04[0xC4];
    FieldC8* m_FieldC8; // +0xC8
};

void MortarObject::vfunc_32(int a1)
{
    sub_00029540(a1);
    if (m_FieldC8) {
        m_FieldC8->sub_00089050((int)this + 52);
    }
}

