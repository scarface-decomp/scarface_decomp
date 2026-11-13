// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LoadSet.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadSet::vfunc_00 (0x00061900, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadSet::vfunc_00 (0x00061900, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_00()
{
    m_Field14 += 1;
}

// ============================================================================
// [VERIFIED] LoadSet::vfunc_01 (0x00061910, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadSet::vfunc_01 (0x00061910, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class LoadSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void LoadSet::vfunc_01()
{
    m_Field14 -= 1;
    if (!m_Field14) {
        vfunc_03(1);
    }
}

// ============================================================================
// [VERIFIED] LoadSet::vfunc_03 (0x00061D10, 80 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadSet::vfunc_03 (0x00061D10, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003A1A74[];
extern "C" int DAT_004762D0;

class LoadSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadSet* vfunc_03(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
    char m_pad20[0x10];
    int m_Field30; // +0x30
};

LoadSet* LoadSet::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_003A1A74;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_01();
        m_Field1C = 0;
    }
    t3 = m_Field30;
    if (m_Field30) {
        ((Object*)t3)->vfunc_01();
        m_Field30 = 0;
    }
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        ((Object*)*(int*)(DAT_004762D0 + 28))->vfunc_05((int)this);
    }
    return this;
}

