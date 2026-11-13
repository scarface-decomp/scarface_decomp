// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtInstancing.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtInstancing::vfunc_01 (0x00264000, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtInstancing::vfunc_01 (0x00264000, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004BC1D4;
extern "C" bool DAT_004BD4C0;
extern "C" void __cdecl sub_0029A8E0(void);

namespace pure3d {

class d3dExtInstancing
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void d3dExtInstancing::vfunc_01()
{
    sub_0029A8E0();
    DAT_004BD4C0 = true;
    DAT_004BC1D4 = 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtInstancing::vfunc_05 (0x002667B0, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtInstancing::vfunc_05 (0x002667B0, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class d3dExtInstancing
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void d3dExtInstancing::vfunc_05()
{
    int t1, t3, t5;

    t1 = m_Field08;
    if (m_Field08) {
        ((Object*)t1)->vfunc_01();
        m_Field08 = 0;
    }
    t3 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t3)->vfunc_01();
        m_Field0C = 0;
    }
    t5 = m_Field10;
    if (m_Field10) {
        ((Object*)t5)->vfunc_01();
        m_Field10 = 0;
    }
}

}

