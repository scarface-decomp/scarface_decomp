// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dExtVisibilityTest.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_01 (0x00237110, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_01 (Proto 0x00237110, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};

int d3dExtVisibilityTest::vfunc_01()
{
    return 16384;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_02 (0x00237120, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00237120
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtVisibilityTest::vfunc_02 (0x00237120, 5 bytes)
extern "C" void __cdecl sub_00315A20(void);

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

void d3dExtVisibilityTest::vfunc_02()
{
    sub_00315A20();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_05 (0x00237180, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_05 (Proto 0x00237180, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
// [VERIFIED] pure3d::d3dExtVisibilityTest::vfunc_07 (0x002371E0, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtVisibilityTest::vfunc_07 (Proto 0x002371E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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

