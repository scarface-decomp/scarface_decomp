// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GameLoadingManager.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameLoadingManager::vfunc_00 (0x001EBA50, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameLoadingManager::vfunc_00 (0x0022B340), which was matched first;
// its addresses and names were swapped for this function's.
// GameLoadingManager::vfunc_00 (0x001EBA50, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB52C[];
extern "C" int DAT_00462F44;
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_000D7D00(void);

class GameLoadingManager
{
public:
    virtual GameLoadingManager* vfunc_00(int a1);
};

GameLoadingManager* GameLoadingManager::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003AB52C;
    DAT_00462F44 = -0x22222223;
    sub_000D7D00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

