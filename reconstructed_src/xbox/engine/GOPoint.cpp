// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GOPoint.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GOPoint::vfunc_00 (0x001AA980, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GOPoint::vfunc_00 (0x001AA980, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00437890[];

class GOPoint
{
public:
    virtual void* vfunc_00();
};

void* GOPoint::vfunc_00()
{
    return DAT_00437890;
}

// ============================================================================
// [VERIFIED] GOPoint::vfunc_01 (0x001ABAC0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GOPoint::vfunc_01 (0x001ABAC0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_00098B90(int);
};

extern "C" char DAT_003BEE24[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001AB560(int);

class GOPoint
{
public:
    virtual void vfunc_00();
    virtual GOPoint* vfunc_01(int a1);
    void sub_00029F90();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0x3];
    int m_Field34; // +0x34
    char m_pad38[0xD];
    unsigned char m_Field45; // +0x45
};

GOPoint* GOPoint::vfunc_01(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003BEE24;
    m_Field30.sub_00098B90(0);
    t2 = m_Field45 & 245;
    m_Field34 = 0;
    m_Field45 = (unsigned char)t2;
    sub_001AB560((int)this);
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

