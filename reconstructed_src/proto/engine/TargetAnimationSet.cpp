// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TargetAnimationSet.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TargetAnimationSet::vfunc_03 (0x000D4AE0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// TargetAnimationSet::vfunc_03 (0x000D4AE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000D4870(void);
extern "C" void __cdecl sub_001FCF60(int);

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
    sub_000D4870();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

