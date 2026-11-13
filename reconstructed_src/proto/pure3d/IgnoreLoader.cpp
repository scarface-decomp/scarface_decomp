// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/IgnoreLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::IgnoreLoader::vfunc_06 (0x00045130, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::IgnoreLoader::vfunc_06 (0x0004C7A0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::IgnoreLoader::vfunc_06 (0x00045130, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_001FDB50();
    void sub_001FDB90();
    void sub_001FDD40();
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
    if (((Object*)a3)->sub_001FDB50()) {
        do {
            ((Object*)a3)->sub_001FDB90();
            ((Object*)a3)->sub_001FDD40();
        } while (((Object*)a3)->sub_001FDB50());
    }
    m_Field0C = 0;
}

}

