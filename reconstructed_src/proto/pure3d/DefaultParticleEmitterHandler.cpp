// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/DefaultParticleEmitterHandler.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::DefaultParticleEmitterHandler::vfunc_05 (0x00224000, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::DefaultParticleEmitterHandler::vfunc_05 (Proto 0x00224000, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001FDD90();
};

extern "C" char sub_00015900[];

namespace pure3d {

class DefaultParticleEmitterHandler
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1, int a2, int a3, int a4);
    void sub_002233F0(int, int, int, int);
};

void DefaultParticleEmitterHandler::vfunc_05(int a1, int a2, int a3, int a4)
{
    if (((Object*)a2)->sub_001FDD90() == (int)sub_00015900) {
        sub_002233F0(a1, a2, a3, a4);
    }
}

}

