// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/IgnoreLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::IgnoreLoader::vfunc_06 (0x0004C7A0, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::IgnoreLoader::vfunc_06 (0x0004C7A0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00240630();
    void sub_00240670();
    void sub_00240820();
};

namespace pure3d {

class IgnoreLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2, int a3, int a4);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void IgnoreLoader::vfunc_06(int a1, int a2, int a3, int a4)
{
    if (((Object*)a3)->sub_00240630()) {
        do {
            ((Object*)a3)->sub_00240670();
            ((Object*)a3)->sub_00240820();
        } while (((Object*)a3)->sub_00240630());
    }
    m_Field0C = 0;
}

}

