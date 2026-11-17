// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/GenericMenuItem.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMenuItem::vfunc_00 (0x001978C0, 71 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuItem::vfunc_00 (0x001978C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_001C49A0();
};

struct Object
{
    void sub_001C5730();
};

extern "C" char DAT_003BBB78[];
extern "C" void __cdecl sub_00027600(int);

class GenericMenuItem
{
public:
    virtual GenericMenuItem* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    Field0C m_Field0C; // +0x0C
};

GenericMenuItem* GenericMenuItem::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003BBB78;
    if (m_Field08) {
        ((Object*)t1)->sub_001C5730();
        sub_00027600(t1);
        m_Field08 = 0;
    }
    m_Field0C.sub_001C49A0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GenericMenuItem::vfunc_03 (0x001AE620, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericMenuItem::vfunc_03 (Proto 0x00181F50), which was matched first;
// its addresses and names were swapped for this function's.
// GenericMenuItem::vfunc_03 (Proto 0x001AE620, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual bool vfunc_03(bool a1);
    char m_pad04[0x1];
    bool m_Field05; // +0x05
};

bool GenericMenuItem::vfunc_03(bool a1)
{
    m_Field05 = a1;
    return a1;
}

