// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/MortarWeaponStateProp.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MortarWeaponStateProp::vfunc_01 (0x001B37B0, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// MortarWeaponStateProp::vfunc_01 (Proto 0x001B37B0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A3328[];
extern "C" char DAT_003A334C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001B8200(void);

class MortarWeaponStateProp
{
public:
    virtual void vfunc_00();
    virtual MortarWeaponStateProp* vfunc_01(int a1);
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

MortarWeaponStateProp* MortarWeaponStateProp::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A334C;
    m_FieldA0 = (int)DAT_003A3328;
    sub_001B8200();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

