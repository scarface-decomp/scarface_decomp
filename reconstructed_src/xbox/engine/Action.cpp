// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Action.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::Action::vfunc_03 (0x0025AAB0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamValue::vfunc_00 (0x0023F0C0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_0039E22C[];
extern "C" void __cdecl sub_00027600(void* p);

namespace fight {

class Action
{
public:
    virtual Action* vfunc_03(unsigned int flags);
};

// Deleting destructor: nothing to destroy but the vtable; frees the object when asked.
#pragma optimize("y", off)
Action* Action::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_0039E22C;
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

