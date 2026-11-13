// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/FirearmSoundPlayer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::FirearmSoundPlayer::vfunc_00 (0x00081450, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::FirearmSoundPlayer::vfunc_00 (0x00081450, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A3688[];
extern "C" char DAT_00422850[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace SoundManager {

class FirearmSoundPlayer
{
public:
    virtual FirearmSoundPlayer* vfunc_00(int a1);
    void sub_00082380();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

FirearmSoundPlayer* FirearmSoundPlayer::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A3688;
    if (m_Field20) {
        m_Field20 = 0;
    }
    sub_00082380();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00422850, (int)this);
    }
    return this;
}

}

