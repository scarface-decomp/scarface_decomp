// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/d3dExtInstancing.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtInstancing::vfunc_01 (0x00232C40, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtInstancing::vfunc_01 (Proto 0x00232C40, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048E120;
extern "C" void __cdecl sub_0025DE10(void);

namespace pure3d {

class d3dExtInstancing
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void d3dExtInstancing::vfunc_01()
{
    sub_0025DE10();
    DAT_0048E120 = true;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtInstancing::vfunc_02 (0x00232C50, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtInstancing::vfunc_02 (Proto 0x00232C50, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0048E120;
extern "C" void __cdecl sub_0025DE10(void);

namespace pure3d {

class d3dExtInstancing
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

void d3dExtInstancing::vfunc_02()
{
    sub_0025DE10();
    DAT_0048E120 = false;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtInstancing::vfunc_05 (0x002354B0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtInstancing::vfunc_05 (Proto 0x002354B0, 43 bytes)
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
};

void d3dExtInstancing::vfunc_05()
{
    int t1, t3;

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
}

}

