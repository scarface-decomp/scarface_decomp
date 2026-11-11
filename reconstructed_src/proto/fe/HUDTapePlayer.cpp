// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDTapePlayer.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 15 functions matched (20.00%). NOT COMPLETE YET.
// The 12 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDTapePlayer::vfunc_00 (0x001761E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTapePlayer::vfunc_00 (0x001761E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00410D28[];

class HUDTapePlayer
{
public:
    virtual void* vfunc_00();
};

void* HUDTapePlayer::vfunc_00()
{
    return DAT_00410D28;
}

// ============================================================================
// [VERIFIED] HUDTapePlayer::vfunc_01 (0x001769D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTapePlayer::vfunc_01 (0x001769D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00176200(void);
extern "C" void __cdecl sub_00025160(int);

class HUDTapePlayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual HUDTapePlayer* vfunc_01(int a1);
};

HUDTapePlayer* HUDTapePlayer::vfunc_01(int a1)
{
    sub_00176200();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] HUDTapePlayer::vfunc_05 (0x0017BA30, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// HUDTapePlayer::vfunc_05 (0x0017BA30, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016E190(void);

class HUDTapePlayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_05();
};

void HUDTapePlayer::vfunc_05()
{
    sub_0016E190();
}

