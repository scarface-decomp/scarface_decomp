// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Occluder.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] occlude::Occluder::vfunc_03 (0x00046D00, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// occlude::Occluder::vfunc_03 (0x00046D00, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A03D0[];
extern "C" void __cdecl sub_000469D0(int);
extern "C" void __cdecl sub_0023F7A0(int);

namespace occlude {

class Occluder
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Occluder* vfunc_03(int a1);
    void sub_002A6940();
};

Occluder* Occluder::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A03D0;
    sub_000469D0((int)this);
    sub_002A6940();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

