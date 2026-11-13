// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/DefaultParticleEmitterHandler.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::DefaultParticleEmitterHandler::vfunc_03 (0x00270C60, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_00027600(void* p);

namespace pure3d {

class DefaultParticleEmitterHandler
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DefaultParticleEmitterHandler* vfunc_03(unsigned int flags);
    void sub_002A6940();
};

#pragma optimize("y", off)
DefaultParticleEmitterHandler* DefaultParticleEmitterHandler::vfunc_03(unsigned int flags)
{
    sub_002A6940();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::DefaultParticleEmitterHandler::vfunc_05 (0x00272200, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::DefaultParticleEmitterHandler::vfunc_05 (0x00272200, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    int sub_00240870();
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
    void sub_00271AF0(int, int, int, int);
};

void DefaultParticleEmitterHandler::vfunc_05(int a1, int a2, int a3, int a4)
{
    if (((Object*)a2)->sub_00240870() == (int)sub_00015900) {
        sub_00271AF0(a1, a2, a3, a4);
    }
}

}

