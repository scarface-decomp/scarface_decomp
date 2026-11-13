// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/GenericSoundPlayer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::GenericSoundPlayer::vfunc_00 (0x00078F50, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::GenericSoundPlayer::vfunc_00 (0x00078F50, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00081DC0();
};

extern "C" char DAT_003A32BC[];
extern "C" char DAT_003A32D8[];
extern "C" char DAT_00422634[];
extern "C" void __cdecl sub_00081980(int);
extern "C" void __cdecl sub_002CF980(int, int);

namespace SoundManager {

class GenericSoundPlayer
{
public:
    virtual GenericSoundPlayer* vfunc_00(int a1);
    int m_Field04; // +0x04
};

GenericSoundPlayer* GenericSoundPlayer::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_003A32D8;
    if (m_Field04) {
        ((Object*)t1)->sub_00081DC0();
        sub_00081980(t1);
    }
    *(int*)this = (int)DAT_003A32BC;
    if (a1 & 1) {
        sub_002CF980((int)DAT_00422634, (int)this);
    }
    return this;
}

}

