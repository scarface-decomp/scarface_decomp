// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleLocomotion.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleLocomotion::vfunc_01 (0x000B1CB0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleLocomotion::vfunc_01 (0x000B1CB0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000ABC80(int);
};

class VehicleLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    int m_Field04; // +0x04
};

void VehicleLocomotion::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field04;
    if (m_Field04) {
        ((Object*)t1)->sub_000ABC80(a1);
        return;
    }
}

// ============================================================================
// [VERIFIED] VehicleLocomotion::vfunc_00 (0x000B1CC0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleLocomotion::vfunc_00 (0x000B1CC0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4FA8[];
extern "C" void __cdecl sub_00027600(int);

class VehicleLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VehicleLocomotion* vfunc_00(int a1);
};

VehicleLocomotion* VehicleLocomotion::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A4FA8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

