// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoundarySphere.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoundarySphere::vfunc_00 (0x0014A680, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoundarySphere::vfunc_00 (0x0014A680, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042E3DC[];

class BoundarySphere
{
public:
    virtual void* vfunc_00();
};

void* BoundarySphere::vfunc_00()
{
    return DAT_0042E3DC;
}

// ============================================================================
// [VERIFIED] BoundarySphere::vfunc_01 (0x0014A6C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// BoundarySphere::vfunc_01 (0x0014A6C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2B3C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00029F90(void);

class BoundarySphere
{
public:
    virtual void vfunc_00();
    virtual BoundarySphere* vfunc_01(int a1);
};

BoundarySphere* BoundarySphere::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B2B3C;
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

