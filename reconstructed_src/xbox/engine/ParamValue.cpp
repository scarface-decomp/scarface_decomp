// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ParamValue.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamValue::vfunc_00 (0x0023F0C0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: resets the vtable and frees the object when asked.
// ============================================================================
extern "C" char DAT_003D4958[];
extern "C" void __cdecl sub_00027600(void* p);

namespace fight {

class ParamValue
{
public:
    virtual ParamValue* vfunc_00(unsigned int flags);
};

// Deleting destructor: nothing to destroy but the vtable; frees the object when asked.
#pragma optimize("y", off)
ParamValue* ParamValue::vfunc_00(unsigned int flags)
{
    *(void**)this = DAT_003D4958;
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

}

