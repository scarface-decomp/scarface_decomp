// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LoadSet.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadSet::vfunc_00 (0x00057170, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadSet::vfunc_00 (0x00061900), which was matched first;
// its addresses and names were swapped for this function's.
// LoadSet::vfunc_00 (0x00057170, 4 bytes)
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
// [VERIFIED] LoadSet::vfunc_01 (0x00057180, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadSet::vfunc_01 (0x00061910), which was matched first;
// its addresses and names were swapped for this function's.
// LoadSet::vfunc_01 (0x00057180, 13 bytes)
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
// [VERIFIED] LoadSet::vfunc_03 (0x000575F0, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadSet::vfunc_03 (Proto 0x000575F0, 80 bytes)
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

extern "C" char DAT_0037D85C[];
extern "C" char DAT_00380B78[];
extern "C" int DAT_0044ADD0;

class LoadSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadSet* vfunc_03(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
    char m_pad20[0xC];
    int m_Field2C; // +0x2C
};

LoadSet* LoadSet::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_00380B78;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_01();
        m_Field1C = 0;
    }
    t3 = m_Field2C;
    if (m_Field2C) {
        ((Object*)t3)->vfunc_01();
        m_Field2C = 0;
    }
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        ((Object*)*(int*)(DAT_0044ADD0 + 24))->vfunc_05((int)this);
    }
    return this;
}

