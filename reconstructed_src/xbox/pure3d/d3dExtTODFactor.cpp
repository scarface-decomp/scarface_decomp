// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtTODFactor.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 17 functions matched (11.76%). NOT COMPLETE YET.
// The 15 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtTODFactor::vfunc_01 (0x00263E40, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtTODFactor::vfunc_01 (0x00263E40, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" float DAT_0045C314;
extern "C" float DAT_0045C318;
extern "C" float DAT_0045C31C;

namespace pure3d {

class d3dExtTODFactor
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2, int a3);
};

int d3dExtTODFactor::vfunc_01(int a1, int a2, int a3)
{
    *(float*)a1 = DAT_0045C314;
    *(float*)a2 = DAT_0045C318;
    *(float*)a3 = DAT_0045C31C;
    return a1;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtTODFactor::vfunc_14 (0x00263FD0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a fixed number kept in the game's data.
// ============================================================================
// bin: xb
// va: 0x00263FD0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000518E0, names and addresses swapped)
// pure3d::d3dExtTODFactor::vfunc_14 (0x00263FD0, 7 bytes)
extern "C" float DAT_004BD4C8;

namespace pure3d {

class d3dExtTODFactor
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual float vfunc_14();
};

float d3dExtTODFactor::vfunc_14()
{
    return DAT_004BD4C8;
}

}

