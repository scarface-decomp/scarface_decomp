// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SimpleLocomotionAnimationSet.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SimpleLocomotionAnimationSet::vfunc_03 (0x000CE920, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SimpleLocomotionAnimationSet::vfunc_03 (Proto 0x000CE920, 34 bytes)
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

extern "C" void __cdecl sub_000CE6D0(void);
extern "C" int __cdecl sub_000D3180(void);

class SimpleLocomotionAnimationSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SimpleLocomotionAnimationSet* vfunc_03(int a1);
};

SimpleLocomotionAnimationSet* SimpleLocomotionAnimationSet::vfunc_03(int a1)
{
    sub_000CE6D0();
    if (a1 & 1) {
        ((Object*)sub_000D3180())->vfunc_05((int)this);
    }
    return this;
}

