// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/StatePropSoundPlayer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::StatePropSoundPlayer::vfunc_00 (0x00076E30, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// SoundManager::StatePropSoundPlayer::vfunc_00 (0x00076E30, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00453964[];
extern "C" void __cdecl sub_00076D90(void);
extern "C" void __cdecl sub_002935D0(int, int);

namespace SoundManager {

class StatePropSoundPlayer
{
public:
    virtual StatePropSoundPlayer* vfunc_00(int a1);
};

StatePropSoundPlayer* StatePropSoundPlayer::vfunc_00(int a1)
{
    sub_00076D90();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00453964, (int)this);
    }
    return this;
}

}

