// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TargetAnimationSet.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TargetAnimationSet::vfunc_03 (0x000E6ED0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SimpleLocomotionAnimationSet::vfunc_03 (0x000E0580), which was matched first;
// its addresses and names were swapped for this function's.
// TargetAnimationSet::vfunc_03 (0x000E6ED0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" int DAT_00487854;
extern "C" void __cdecl sub_000E6E50(void);

class TargetAnimationSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TargetAnimationSet* vfunc_03(int a1);
};

TargetAnimationSet* TargetAnimationSet::vfunc_03(int a1)
{
    sub_000E6E50();
    if (a1 & 1) {
        ((Object*)DAT_00487854)->vfunc_05((int)this);
    }
    return this;
}

