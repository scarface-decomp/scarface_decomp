// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/TextBible.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::TextBible::vfunc_03 (0x0024DF30, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::TextBible::vfunc_03 (0x0024DF30, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field0C
{
    void sub_0029C520();
};

extern "C" char DAT_003D52B8[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0024D2C0(int);

namespace pure3d {

class TextBible
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextBible* vfunc_03(int a1);
    void sub_002A6940();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

TextBible* TextBible::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003D52B8;
    sub_0024D2C0((int)this);
    if (m_Field0C) {
        m_Field0C->sub_0029C520();
    }
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

