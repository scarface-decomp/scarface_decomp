// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/Page.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Page::vfunc_03 (0x0020DAD0, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Page::vfunc_03 (Proto 0x0020DAD0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE644[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00249530(void);

namespace pure3d { namespace frontend {

class Page
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Page* vfunc_03(int a1);
};

Page* Page::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003AE644;
    sub_00249530();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Page::vfunc_08 (0x00249400, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Page::vfunc_08 (Proto 0x00249400, 52 bytes)
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
};

namespace pure3d { namespace frontend {

class Page
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
    char m_pad04[0xD];
    bool m_Field11; // +0x11
    char m_pad12[0x2];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void Page::vfunc_08()
{
    int r_ebx, r_esi;

    r_ebx = m_Field18;
    r_ebx -= m_Field14;
    r_ebx >>= 2;
    r_esi = 0;
    if (r_ebx > 0) {
        do {
            *(bool*)(*(int*)(m_Field14 + (r_esi * 4)) + 17) = m_Field11;
            ((Object*)*(int*)(m_Field14 + (r_esi * 4)))->vfunc_08();
            r_esi += 1;
        } while (r_esi < r_ebx);
    }
}

} }

