// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ShadowGenerator.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowGenerator::vfunc_03 (0x0003AAC0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ShadowGenerator::vfunc_03 (0x0003EE30), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowGenerator::vfunc_03 (0x0003AAC0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00212770();
};

extern "C" char DAT_0037D85C[];
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class ShadowGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ShadowGenerator* vfunc_03(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

ShadowGenerator* ShadowGenerator::vfunc_03(int a1)
{
    m_Field08.sub_00212770();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

