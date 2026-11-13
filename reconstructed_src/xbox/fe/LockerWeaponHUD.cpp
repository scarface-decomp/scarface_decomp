// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/LockerWeaponHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 8 functions matched (25.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LockerWeaponHUD::vfunc_00 (0x001A5980, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LockerWeaponHUD::vfunc_00 (0x001A5980, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004361C0[];

class LockerWeaponHUD
{
public:
    virtual void* vfunc_00();
};

void* LockerWeaponHUD::vfunc_00()
{
    return DAT_004361C0;
}

// ============================================================================
// [VERIFIED] LockerWeaponHUD::vfunc_01 (0x001A5AB0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LockerWeaponHUD::vfunc_01 (0x001A5AB0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BE4E4[];
extern "C" char DAT_003BE4EC[];
extern "C" char DAT_003BE504[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00190220(void);

class LockerWeaponHUD
{
public:
    virtual void vfunc_00();
    virtual LockerWeaponHUD* vfunc_01(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0xA8];
    int m_Field110; // +0x110
};

LockerWeaponHUD* LockerWeaponHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003BE504;
    m_Field64 = (int)DAT_003BE4EC;
    m_Field110 = (int)DAT_003BE4E4;
    sub_00190220();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

