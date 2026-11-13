// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISVehicleAnimationTrack.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISVehicleAnimationTrack::vfunc_08 (0x001639D0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SpeedCondition::vfunc_08 (0x000DD280), which was matched first;
// its addresses and names were swapped for this function's.
// NISVehicleAnimationTrack::vfunc_08 (0x001639D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045DEC0;

class NISVehicleAnimationTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1);
};

int NISVehicleAnimationTrack::vfunc_08(int a1)
{
    return *(int*)(DAT_0045DEC0 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] NISVehicleAnimationTrack::vfunc_03 (0x00164500, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISCharacterDamageTrack::vfunc_03 (0x00185EE0), which was matched first;
// its addresses and names were swapped for this function's.
// NISVehicleAnimationTrack::vfunc_03 (0x00164500, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    void sub_001B7A10();
};

extern "C" char DAT_00395164[];
extern "C" void __cdecl sub_001FCF60(int);

class NISVehicleAnimationTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISVehicleAnimationTrack* vfunc_03(int a1);
    void sub_00020600();
    char m_pad04[0x10];
    Field18 m_Field14; // +0x14
    char m_pad15[0x3];
    Field18 m_Field18; // +0x18
};

NISVehicleAnimationTrack* NISVehicleAnimationTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00395164;
    m_Field18.sub_001B7A10();
    m_Field14.sub_001B7A10();
    sub_00020600();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

