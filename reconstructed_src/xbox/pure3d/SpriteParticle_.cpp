// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/SpriteParticle_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_04 (0x00271A00, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_04 (Proto 0x00223320), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_04 (Proto 0x00271A00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002957F0(void);

namespace pure3d { class SpriteParticle; }

namespace pure3d { 
template <class T0> class ParticleAllocatorTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};
}

template <> void pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_04()
{
    sub_002957F0();
}

// ============================================================================
// [VERIFIED] pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle>::vfunc_03 (0x00271A10, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamString<fight::EnterExitScriptTrack>::vfunc_00 (0x0023E8B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00271A10
// what: Deleting destructor: runs the destructor, then frees the object when asked to.
// tool: Claude Opus 5.5 (byte copy of the matched 0x0023B160 with its own addresses, examiner A6: ?$ParticleAllocatorTemplate@VEnterExitScriptTrack@pure3d@@@pure3d::vfunc_03)

extern "C" void __cdecl sub_00027600(void* p);

class Class_00271A10
{
public:
    virtual void vfunc_03();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Class_00271A10* sub_00271A10(unsigned int flags);
    void sub_00271A40();
};

#pragma optimize("y", off)
Class_00271A10* Class_00271A10::sub_00271A10(unsigned int flags)
{
    sub_00271A40();
    if (flags & 1)
        sub_00027600(this);
    return this;
}
#pragma optimize("", on)

