// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/VehicleWeaponStateProp.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleWeaponStateProp::vfunc_00 (0x001F27C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleWeaponStateProp::vfunc_00 (0x001F27C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043E7D4[];

class VehicleWeaponStateProp
{
public:
    virtual void* vfunc_00();
};

void* VehicleWeaponStateProp::vfunc_00()
{
    return DAT_0043E7D4;
}

// ============================================================================
// [VERIFIED] VehicleWeaponStateProp::vfunc_73 (0x001F27F0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleWeaponStateProp::vfunc_73 (0x001F27F0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001F5360(void);

class VehicleWeaponStateProp
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_73();
};

void VehicleWeaponStateProp::vfunc_73()
{
    sub_001F5360();
}

// ============================================================================
// [VERIFIED] VehicleWeaponStateProp::vfunc_01 (0x001F2800, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MeleeWeaponStateProp::vfunc_01 (0x001EC690), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleWeaponStateProp::vfunc_01 (0x001F2800, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA0B4[];
extern "C" char DAT_003CA0D4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001F2990(void);

class VehicleWeaponStateProp
{
public:
    virtual void vfunc_00();
    virtual VehicleWeaponStateProp* vfunc_01(int a1);
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
};

VehicleWeaponStateProp* VehicleWeaponStateProp::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CA0D4;
    m_FieldA8 = (int)DAT_003CA0B4;
    sub_001F2990();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

