// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/CollisionSoundPlayer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CollisionSoundPlayer::vfunc_00 (0x0007F8B0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as BoatSoundPlayer::vfunc_00 (0x00079FD0), which was matched first;
// its addresses and names were swapped for this function's.
// CollisionSoundPlayer::vfunc_00 (0x0007F8B0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004227BC[];
extern "C" void __cdecl sub_0007F800(void);
extern "C" void __cdecl sub_002CF980(int, int);

class CollisionSoundPlayer
{
public:
    virtual CollisionSoundPlayer* vfunc_00(int a1);
};

CollisionSoundPlayer* CollisionSoundPlayer::vfunc_00(int a1)
{
    sub_0007F800();
    if (a1 & 1) {
        sub_002CF980((int)DAT_004227BC, (int)this);
    }
    return this;
}

