// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/SatPhoneWeaponHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SatPhoneWeaponHUD::vfunc_00 (0x001BC640, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SatPhoneWeaponHUD::vfunc_00 (0x001BC640, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436194[];

class SatPhoneWeaponHUD
{
public:
    virtual void* vfunc_00();
};

void* SatPhoneWeaponHUD::vfunc_00()
{
    return DAT_00436194;
}

// ============================================================================
// [VERIFIED] SatPhoneWeaponHUD::vfunc_01 (0x001BC750, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LockerWeaponHUD::vfunc_01 (0x001A5AB0), which was matched first;
// its addresses and names were swapped for this function's.
// SatPhoneWeaponHUD::vfunc_01 (0x001BC750, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C1B58[];
extern "C" char DAT_003C1B60[];
extern "C" char DAT_003C1B7C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00190220(void);

class SatPhoneWeaponHUD
{
public:
    virtual void vfunc_00();
    virtual SatPhoneWeaponHUD* vfunc_01(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0xA8];
    int m_Field110; // +0x110
};

SatPhoneWeaponHUD* SatPhoneWeaponHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C1B7C;
    m_Field64 = (int)DAT_003C1B60;
    m_Field110 = (int)DAT_003C1B58;
    sub_00190220();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

