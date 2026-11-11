// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SoundFadeTrack.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundFadeTrack::vfunc_03 (0x000E9F40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// SoundFadeTrack::vfunc_03 (0x000E9F40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A90D4[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00022970(void);

class SoundFadeTrack
{
public:
    virtual void vfunc_00();
    virtual SoundFadeTrack* vfunc_03(int a1);
};

SoundFadeTrack* SoundFadeTrack::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A90D4;
    sub_00022970();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

