// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/ParticleController.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 10 functions matched (10.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_03 (0x0024E9C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleController::vfunc_03 (0x0024E9C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0024E940(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ParticleController
{
public:
    virtual ParticleController* vfunc_03(int a1);
};

ParticleController* ParticleController::vfunc_03(int a1)
{
    sub_0024E940();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

