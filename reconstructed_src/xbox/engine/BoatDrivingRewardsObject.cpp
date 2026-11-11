// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoatDrivingRewardsObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_04 (0x0021C550, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_04 (0x0021C550, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0021C4F0(void);

class BoatDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void BoatDrivingRewardsObject::vfunc_04()
{
    sub_0021C4F0();
}

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_00 (0x0021C710, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_00 (0x0021C710, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0044D464[];

class BoatDrivingRewardsObject
{
public:
    virtual void* vfunc_00();
};

void* BoatDrivingRewardsObject::vfunc_00()
{
    return DAT_0044D464;
}

// ============================================================================
// [VERIFIED] BoatDrivingRewardsObject::vfunc_01 (0x0021C8D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// BoatDrivingRewardsObject::vfunc_01 (0x0021C8D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0021C720(void);
extern "C" void __cdecl sub_00027600(int);

class BoatDrivingRewardsObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BoatDrivingRewardsObject* vfunc_01(int a1);
};

BoatDrivingRewardsObject* BoatDrivingRewardsObject::vfunc_01(int a1)
{
    sub_0021C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

