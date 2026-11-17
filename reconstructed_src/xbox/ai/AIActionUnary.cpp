// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionUnary.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionUnary::vfunc_06 (0x0011FBD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LocomotionAction::vfunc_06 (0x000E5480), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionUnary::vfunc_06 (0x0011FBD0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0011E1A0();
};

class AIActionUnary
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
};

void AIActionUnary::vfunc_06()
{
    m_Field08->sub_0011E1A0();
}

// ============================================================================
// [VERIFIED] AIActionUnary::vfunc_00 (0x0011FFB0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionUnary::vfunc_00 (Proto 0x00104CE0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionUnary::vfunc_00 (Proto 0x0011FFB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_003AAAC8[];
extern "C" char DAT_003AE86C[];
extern "C" void __cdecl sub_00027600(int);

class AIActionUnary
{
public:
    virtual AIActionUnary* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

AIActionUnary* AIActionUnary::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003AE86C;
    if (m_Field08) {
        ((Object*)t1)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

