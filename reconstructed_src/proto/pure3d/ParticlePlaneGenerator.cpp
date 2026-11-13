// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ParticlePlaneGenerator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticlePlaneGenerator::vfunc_05 (0x00257AC0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::PrimGroupSkinnedOptimized::vfunc_05 (0x00293060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticlePlaneGenerator::vfunc_05 (0x00257AC0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00257920(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class ParticlePlaneGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ParticlePlaneGenerator::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(88);
    if (t1) {
        return ((Object*)t1)->sub_00257920((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ParticlePlaneGenerator::vfunc_03 (0x00257CE0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticlePlaneGenerator::vfunc_03 (0x00257CE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00257A50(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ParticlePlaneGenerator
{
public:
    virtual ParticlePlaneGenerator* vfunc_03(int a1);
};

ParticlePlaneGenerator* ParticlePlaneGenerator::vfunc_03(int a1)
{
    sub_00257A50();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

