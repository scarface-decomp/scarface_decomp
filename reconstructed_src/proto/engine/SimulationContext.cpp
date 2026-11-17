// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SimulationContext.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ravenphysics::SimulationContext::vfunc_03 (0x002B66D0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ravenphysics::SimulationContext::vfunc_03 (Proto 0x002B66D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_002B6680();
};

extern "C" char DAT_0037D85C[];
extern "C" void __cdecl sub_001FCF60(int);

namespace ravenphysics {

class SimulationContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SimulationContext* vfunc_03(int a1);
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

SimulationContext* SimulationContext::vfunc_03(int a1)
{
    m_Field14.sub_002B6680();
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

