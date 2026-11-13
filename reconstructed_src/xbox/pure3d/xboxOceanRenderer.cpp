// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/xboxOceanRenderer.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 11 functions matched (54.55%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_11 (0x002565C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_11 (0x002565C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class xboxOceanRenderer
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
    virtual void vfunc_10();
    virtual int vfunc_11(int a1);
    int m_Field04; // +0x04
};

int xboxOceanRenderer::vfunc_11(int a1)
{
    m_Field04 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_03 (0x002967B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_03 (0x002967B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3);
};

int xboxOceanRenderer::vfunc_03(int a1, int a2, int a3)
{
    *(int*)a3 = 0;
    *(int*)(a3 + 4) = 0x3F800000;
    *(int*)(a3 + 8) = 0;
    return a3;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_06 (0x00296DA0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_06 (0x00296DA0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002A9290();
};

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void xboxOceanRenderer::vfunc_06()
{
    int t1;

    t1 = m_Field10;
    if (m_Field10) {
        ((Object*)t1)->sub_002A9290();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_08 (0x00296DB0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_08 (0x00296DB0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class xboxOceanRenderer
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
    virtual bool vfunc_08(bool a1);
    char m_pad04[0x44C];
    bool m_Field450; // +0x450
};

bool xboxOceanRenderer::vfunc_08(bool a1)
{
    m_Field450 = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_09 (0x00296DC0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::xboxOceanRenderer::vfunc_09 (0x00296DC0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class xboxOceanRenderer
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
    virtual bool vfunc_09();
    char m_pad04[0x44C];
    bool m_Field450; // +0x450
};

bool xboxOceanRenderer::vfunc_09()
{
    return m_Field450;
}

}

// ============================================================================
// [VERIFIED] pure3d::xboxOceanRenderer::vfunc_00 (0x00297AB0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class xboxOceanRenderer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual xboxOceanRenderer* vfunc_00(unsigned int flags);
    void sub_00297000();
};

#pragma optimize("y", off)
xboxOceanRenderer* xboxOceanRenderer::vfunc_00(unsigned int flags)
{
    sub_00297000();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

