// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleMaterialProperties.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleMaterialProperties::vfunc_00 (0x0020CC80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleMaterialProperties::vfunc_00 (0x0020CC80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00445C6C[];

class VehicleMaterialProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleMaterialProperties::vfunc_00()
{
    return DAT_00445C6C;
}

// ============================================================================
// [VERIFIED] VehicleMaterialProperties::vfunc_04 (0x0020CC90, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatPitchClampProperties::vfunc_04 (0x00200E50), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleMaterialProperties::vfunc_04 (0x0020CC90, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_000A74C0();
};

extern "C" void __stdcall sub_0002B700(int);

class VehicleMaterialProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

void VehicleMaterialProperties::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field20.sub_000A74C0();
}

// ============================================================================
// [VERIFIED] VehicleMaterialProperties::vfunc_01 (0x0020CE20, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleMaterialProperties::vfunc_01 (0x0020CE20, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CD3DC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002C720(void);

class VehicleMaterialProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleMaterialProperties* vfunc_01(int a1);
};

VehicleMaterialProperties* VehicleMaterialProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CD3DC;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

