// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleSeveredPartEffectProperties.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleSeveredPartEffectProperties::vfunc_00 (0x001D3EB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSeveredPartEffectProperties::vfunc_00 (0x001D3EB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00421614[];

class VehicleSeveredPartEffectProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleSeveredPartEffectProperties::vfunc_00()
{
    return DAT_00421614;
}

// ============================================================================
// [VERIFIED] VehicleSeveredPartEffectProperties::vfunc_01 (0x001D43E0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleSeveredPartEffectProperties::vfunc_01 (0x001D43E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A834C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class VehicleSeveredPartEffectProperties
{
public:
    virtual void vfunc_00();
    virtual VehicleSeveredPartEffectProperties* vfunc_01(int a1);
};

VehicleSeveredPartEffectProperties* VehicleSeveredPartEffectProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A834C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] VehicleSeveredPartEffectProperties::vfunc_05 (0x001D5CF0, 76 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// VehicleSeveredPartEffectProperties::vfunc_05 (Proto 0x001D5CF0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009B380();
};

extern "C" char DAT_003A8968[];
extern "C" void __stdcall sub_00028C40(int);
extern "C" void __cdecl sub_001D4C20(int, int, int, int);

class VehicleSeveredPartEffectProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
};

void VehicleSeveredPartEffectProperties::vfunc_05(int a1)
{
    int r_ebp, r_ebx, r_edi, r_esi;

    r_esi = (int)this;
    sub_00028C40(a1);
    r_ebp = r_esi + 32;
    r_edi = r_ebp;
    r_esi += 52;
    r_ebx = 3;
    do {
        sub_001D4C20(*(int*)r_esi, r_esi + 4, r_edi, (int)DAT_003A8968);
        r_edi += 4;
        r_esi += 8;
        r_ebx -= 1;
    } while (r_ebx);
    ((Object*)r_ebp)->sub_0009B380();
}

