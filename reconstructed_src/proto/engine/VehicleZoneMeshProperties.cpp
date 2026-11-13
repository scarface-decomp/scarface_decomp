// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/VehicleZoneMeshProperties.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] VehicleZoneMeshProperties::vfunc_00 (0x001D23D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneMeshProperties::vfunc_00 (0x001D23D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042134C[];

class VehicleZoneMeshProperties
{
public:
    virtual void* vfunc_00();
};

void* VehicleZoneMeshProperties::vfunc_00()
{
    return DAT_0042134C;
}

// ============================================================================
// [VERIFIED] VehicleZoneMeshProperties::vfunc_01 (0x001D3090, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundPlayTrack::vfunc_03 (0x000E9E90), which was matched first;
// its addresses and names were swapped for this function's.
// VehicleZoneMeshProperties::vfunc_01 (0x001D3090, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_0007D1B0();
};

extern "C" char DAT_003A7C8C[];
extern "C" void __cdecl sub_00025160(int);

class VehicleZoneMeshProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VehicleZoneMeshProperties* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x1C];
    Field20 m_Field20; // +0x20
};

VehicleZoneMeshProperties* VehicleZoneMeshProperties::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A7C8C;
    m_Field20.sub_0007D1B0();
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

