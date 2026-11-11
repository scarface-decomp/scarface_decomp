// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/SemiConcreteClassRep_AIActionTreeCreatingTask_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SemiConcreteClassRep<AIActionTreeCreatingTask>::vfunc_02 (0x001017B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// SemiConcreteClassRep<AIActionTreeCreatingTask>::vfunc_02 (0x001017B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00403D3C;
extern "C" int DAT_00403D40;
extern "C" char DAT_00403ADC[];
extern "C" int DAT_00403B00;
extern "C" void __cdecl sub_001012C0(void);
extern "C" void __cdecl sub_000660D0(int, int);

class AIActionTreeCreatingTask;

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void SemiConcreteClassRep<AIActionTreeCreatingTask>::vfunc_02()
{
    sub_000660D0(DAT_00403B00, DAT_00403D3C);
    DAT_00403D40 = (int)DAT_00403ADC;
    sub_001012C0();
}

