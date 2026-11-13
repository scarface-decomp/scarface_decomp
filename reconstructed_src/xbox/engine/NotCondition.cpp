// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NotCondition.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::NotCondition::vfunc_03 (0x0023E150, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D4624[];
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace fight {

class NotCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NotCondition* vfunc_03(unsigned int flags);
    void sub_00239F00();
};

#pragma optimize("y", off)
NotCondition* NotCondition::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D4624;
    sub_00239F00();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

