// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleZoneEffectProperties.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleZoneEffectProperties::vfunc_00 (0x0020D690, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns VehicleZoneEffectProperties's static class record (ConcreteClassRep<VehicleZoneEffectProperties>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneEffectProperties::vfunc_00 (0x0020D690, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004479D8[];

class VehicleZoneEffectProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleZoneEffectProperties::vfunc_00()
{
    return DAT_004479D8;
}

// ============================================================================
// [VERIFIED] VehicleZoneEffectProperties::vfunc_01 (0x0020E580, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: VehicleZoneEffectProperties's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneEffectProperties::vfunc_01 (0x0020E580, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CDF0C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002C720(void);

class VehicleZoneEffectProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleZoneEffectProperties* vfunc_01(int a1);
};

VehicleZoneEffectProperties* VehicleZoneEffectProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CDF0C;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleZoneEffectProperties::vfunc_04 (0x0020E5B0, 55 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as VehicleZoneEffectProperties::vfunc_05 (Proto 0x001D34E0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneEffectProperties::vfunc_04 (Proto 0x0020E5B0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020E4A0(int);
};

extern "C" void __stdcall sub_0002B700(int);

class VehicleZoneEffectProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void VehicleZoneEffectProperties::vfunc_04(int a1)
{
    int r_ebx, r_edi, r_esi;

    r_esi = (int)this;
    sub_0002B700(a1);
    r_edi = r_esi + 392;
    r_esi += 32;
    r_ebx = 30;
    do {
        ((Object*)r_edi)->sub_0020E4A0(r_esi);
        r_esi += 12;
        r_edi += 16;
        r_ebx -= 1;
    } while (r_ebx);
}

