// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SemiConcreteClassRep_CameraObject_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SemiConcreteClassRep<CameraObject>::vfunc_02 (0x0015C7C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// SemiConcreteClassRep<CameraObject>::vfunc_02 (0x0015C7C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042E924;
extern "C" int DAT_0042E928;
extern "C" char DAT_0041B6B4[];
extern "C" int DAT_0041B6D4;
extern "C" void __cdecl sub_0015C660(void);
extern "C" void __cdecl sub_00070520(int, int);

class CameraObject;

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void SemiConcreteClassRep<CameraObject>::vfunc_02()
{
    sub_00070520(DAT_0041B6D4, DAT_0042E924);
    DAT_0042E928 = (int)DAT_0041B6B4;
    sub_0015C660();
}

