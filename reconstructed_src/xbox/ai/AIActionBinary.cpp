// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionBinary.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionBinary::vfunc_04 (0x0011F690, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionBinary::vfunc_04 (0x0011F690, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AIActionBinary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

void AIActionBinary::vfunc_04()
{
    vfunc_05();
    vfunc_06();
}

// ============================================================================
// [VERIFIED] AIActionBinary::vfunc_06 (0x0011F6D0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionBinary::vfunc_04 (Proto 0x001042E0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionBinary::vfunc_06 (Proto 0x0011F6D0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0011E1A0();
};

class AIActionBinary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field08* m_Field0C; // +0x0C
};

void AIActionBinary::vfunc_06()
{
    m_Field08->sub_0011E1A0();
    m_Field0C->sub_0011E1A0();
}

// ============================================================================
// [VERIFIED] AIActionBinary::vfunc_00 (0x0011FE10, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionBinary::vfunc_00 (Proto 0x00104B40), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionBinary::vfunc_00 (Proto 0x0011FE10, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003AAAC8[];
extern "C" char DAT_003AE84C[];
extern "C" void __cdecl sub_00027600(int);

class AIActionBinary
{
public:
    virtual AIActionBinary* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

AIActionBinary* AIActionBinary::vfunc_00(int a1)
{
    int t1, t3;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003AE84C;
    if (m_Field08) {
        ((Object*)t1)->vfunc_00(1);
    }
    t3 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t3)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

