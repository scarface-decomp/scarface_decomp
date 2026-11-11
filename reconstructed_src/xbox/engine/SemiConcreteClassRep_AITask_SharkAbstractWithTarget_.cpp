// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SemiConcreteClassRep_AITask_SharkAbstractWithTarget_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SemiConcreteClassRep<AITask_SharkAbstractWithTarget>::vfunc_02 (0x0011AFF0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// SemiConcreteClassRep<AITask_SharkAbstractWithTarget>::vfunc_02 (0x0011AFF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004297B0;
extern "C" int DAT_004297B4;
extern "C" char DAT_00428EA0[];
extern "C" int DAT_00428EC0;
extern "C" void __cdecl sub_00070520(int, int);

class AITask_SharkAbstractWithTarget;

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void SemiConcreteClassRep<AITask_SharkAbstractWithTarget>::vfunc_02()
{
    sub_00070520(DAT_00428EC0, DAT_004297B0);
    DAT_004297B4 = (int)DAT_00428EA0;
}

