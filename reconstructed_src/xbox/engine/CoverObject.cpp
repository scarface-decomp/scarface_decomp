// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CoverObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CoverObject::vfunc_00 (0x00112E50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CoverObject::vfunc_00 (0x00112E50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042B010[];

class CoverObject
{
public:
    virtual void* vfunc_00();
};

void* CoverObject::vfunc_00()
{
    return DAT_0042B010;
}

// ============================================================================
// [VERIFIED] CoverObject::vfunc_01 (0x001130B0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CoverObject::vfunc_01 (0x001130B0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00112BC0(int);
};

extern "C" char DAT_003AD344[];
extern "C" int DAT_004897F0;
extern "C" void __cdecl sub_00027600(int);

class CoverObject
{
public:
    virtual void vfunc_00();
    virtual CoverObject* vfunc_01(int a1);
    void sub_00029F90();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

CoverObject* CoverObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003AD344;
    if ((m_Field74 & 2032) != 2032) {
        ((Object*)DAT_004897F0)->sub_00112BC0((int)this);
    }
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CoverObject::vfunc_29 (0x00113100, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CoverObject::vfunc_29 (0x00113100, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00111EE0(int, int);
};

extern "C" int DAT_004897F0;

class CoverObject
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
    virtual int vfunc_29(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x4];
    int m_Field74; // +0x74
};

int CoverObject::vfunc_29(int a1)
{
    int r_eax;

    r_eax = a1;
    m_Field64 = *(int*)r_eax;
    m_Field68 = *(int*)(r_eax + 4);
    m_Field6C = *(int*)(r_eax + 8);
    if ((m_Field74 & 2032) != 2032) {
        r_eax = ((Object*)DAT_004897F0)->sub_00111EE0((int)this, a1);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] CoverObject::vfunc_32 (0x00113140, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CoverObject::vfunc_32 (0x00113140, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CoverObject
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
    virtual void vfunc_30(int);
    virtual void vfunc_31();
    virtual void vfunc_32(int a1);
    void sub_00029540(int);
};

void CoverObject::vfunc_32(int a1)
{
    vfunc_30(a1 + 32);
    sub_00029540(a1);
}

