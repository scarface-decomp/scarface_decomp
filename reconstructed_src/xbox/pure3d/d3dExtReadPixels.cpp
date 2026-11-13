// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtReadPixels.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtReadPixels::vfunc_01 (0x00264190, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::d3dExtReadPixels::vfunc_01 (0x00264190, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    void sub_0029AB90(int, int, int, int);
};

namespace pure3d {

class d3dExtReadPixels
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2, int a3);
    int m_Field04; // +0x04
};

void d3dExtReadPixels::vfunc_01(int a1, int a2, int a3)
{
    ((Object*)*(int*)(m_Field04 + 540))->sub_0029AB90(a3, ((*(int*)(a2 + 12) - *(int*)(a2 + 4)) * (*(int*)(a2 + 8) - *(int*)a2)) << 2, a2, a1);
}

}

