// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GenericVehicleCamera.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_00 (0x00157F20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GenericVehicleCamera::vfunc_00 (0x00157F20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042EFB4[];

class GenericVehicleCamera
{
public:
    virtual void* vfunc_00();
};

void* GenericVehicleCamera::vfunc_00()
{
    return DAT_0042EFB4;
}

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_01 (0x00158300, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// GenericVehicleCamera::vfunc_01 (0x00158300, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3384[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001522F0(void);

class GenericVehicleCamera
{
public:
    virtual void vfunc_00();
    virtual GenericVehicleCamera* vfunc_01(int a1);
};

GenericVehicleCamera* GenericVehicleCamera::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B3384;
    sub_001522F0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GenericVehicleCamera::vfunc_40 (0x00158950, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// GenericVehicleCamera::vfunc_40 (0x00158950, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00158480(void);

class GenericVehicleCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_40();
};

void GenericVehicleCamera::vfunc_40()
{
    sub_00158480();
}

