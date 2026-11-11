// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MountedWeaponStateProp.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MountedWeaponStateProp::vfunc_30 (0x001B8430, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// MountedWeaponStateProp::vfunc_30 (0x001B8430, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B5B00(void);

class MountedWeaponStateProp
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_30();
};

void MountedWeaponStateProp::vfunc_30()
{
    sub_001B5B00();
}

// ============================================================================
// [VERIFIED] MountedWeaponStateProp::vfunc_00 (0x001B8C10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// MountedWeaponStateProp::vfunc_00 (0x001B8C10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00418238[];

class MountedWeaponStateProp
{
public:
    virtual void* vfunc_00();
};

void* MountedWeaponStateProp::vfunc_00()
{
    return DAT_00418238;
}

// ============================================================================
// [VERIFIED] MountedWeaponStateProp::vfunc_01 (0x001B97B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// MountedWeaponStateProp::vfunc_01 (0x001B97B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001B8BB0(void);
extern "C" void __cdecl sub_00025160(int);

class MountedWeaponStateProp
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MountedWeaponStateProp* vfunc_01(int a1);
};

MountedWeaponStateProp* MountedWeaponStateProp::vfunc_01(int a1)
{
    sub_001B8BB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

