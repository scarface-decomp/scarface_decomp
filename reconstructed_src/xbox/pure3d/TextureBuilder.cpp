// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/TextureBuilder.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::TextureBuilder::vfunc_09 (0x0025FE00, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::TextureBuilder::vfunc_09 (0x0025FE00, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class TextureBuilder
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
    virtual int vfunc_09(int a1);
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

int TextureBuilder::vfunc_09(int a1)
{
    m_Field28 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureBuilder::vfunc_10 (0x00262190, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TextureBuilder::vfunc_10 (Proto 0x0021B7E0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::TextureBuilder::vfunc_10 (Proto 0x00262190, 22 bytes)
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual int vfunc_14(int);
};

namespace pure3d {

class TextureBuilder
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
    virtual int vfunc_10();
    int m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
};

int TextureBuilder::vfunc_10()
{
    int r_eax;

    r_eax = m_Field04;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 12);
        r_eax = ((Object*)r_eax)->vfunc_14(m_Field1C);
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureBuilder::vfunc_05 (0x002621E0, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TextureBuilder::vfunc_05 (Proto 0x0021B830), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::TextureBuilder::vfunc_05 (Proto 0x002621E0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class TextureBuilder
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x4];
    int m_Field14; // +0x14
};

int TextureBuilder::vfunc_05()
{
    if (m_Field04) {
        if (!m_Field14) goto L_15;
        return *(int*)(m_Field0C + 84);
    }
L_15:
    return 0;
}

}

