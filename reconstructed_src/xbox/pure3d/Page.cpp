// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Page.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Page::vfunc_08 (0x0028D830, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Page::vfunc_08 (Proto 0x00249400), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::Page::vfunc_08 (Proto 0x0028D830, 52 bytes)
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

// ============================================================================
// [VERIFIED] pure3d::frontend::Page::vfunc_07 (0x0028D870, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Page::vfunc_07 (0x0028D870, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
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
    virtual void vfunc_07(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void Page::vfunc_07(int a1)
{
    int r_edi, r_esi;

    r_edi = m_Field18;
    r_edi -= m_Field14;
    r_edi >>= 2;
    r_esi = 0;
    if (r_edi > 0) {
        do {
            ((Object*)*(int*)(m_Field14 + (r_esi * 4)))->vfunc_07(a1);
            r_esi += 1;
        } while (r_esi < r_edi);
    }
}

} }

