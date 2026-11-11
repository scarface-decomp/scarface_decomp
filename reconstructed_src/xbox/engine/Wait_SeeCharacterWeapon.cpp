// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Wait_SeeCharacterWeapon.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_SeeCharacterWeapon::vfunc_03 (0x00138CB0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_SeeCharacterWeapon::vfunc_03 (0x00138CB0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00138770(void);
extern "C" void __cdecl sub_00027600(int);

namespace AICommandWaits {

class Wait_SeeCharacterWeapon
{
public:
    virtual Wait_SeeCharacterWeapon* vfunc_03(int a1);
};

Wait_SeeCharacterWeapon* Wait_SeeCharacterWeapon::vfunc_03(int a1)
{
    sub_00138770();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

