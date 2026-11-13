// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ParticleController.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 10 functions matched (10.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticleController::vfunc_03 (0x00292050, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class ParticleController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleController* vfunc_03(unsigned int flags);
    void sub_00291FD0();
};

#pragma optimize("y", off)
ParticleController* ParticleController::vfunc_03(unsigned int flags)
{
    sub_00291FD0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

