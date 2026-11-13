// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtVisibilityTest.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_04 (0x00268110, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_04 (0x00268110, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" int __stdcall sub_00329970(int, int, int);

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
};

int d3dExtVisibilityTest::vfunc_04(int a1)
{
    int r_esi;

    r_esi = a1;
    do {
    } while (sub_00329970(r_esi, (int)(&a1), 0) == -0x7789F7D8);
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_05 (0x00268140, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_05 (0x00268140, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};

int d3dExtVisibilityTest::vfunc_05(int a1)
{
    int t1;

    t1 = m_Field60;
    *(int*)((int)this + (m_Field60 * 4) + 4) = a1;
    m_Field60 += 1;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_07 (0x002681A0, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_07 (0x002681A0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1);
};

int d3dExtVisibilityTest::vfunc_07(int a1)
{
    return *(int*)((int)this + (a1 * 4) + 56);
}

}

