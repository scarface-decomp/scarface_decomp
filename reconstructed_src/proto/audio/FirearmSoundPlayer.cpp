// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/FirearmSoundPlayer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::FirearmSoundPlayer::vfunc_00 (0x000754F0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::FirearmSoundPlayer::vfunc_00 (Proto 0x000754F0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00077320(int);
};

extern "C" char DAT_00382BC0[];
extern "C" char DAT_00453918[];
extern "C" int DAT_0045398C;
extern "C" void __cdecl sub_002935D0(int, int);

namespace SoundManager {

class FirearmSoundPlayer
{
public:
    virtual FirearmSoundPlayer* vfunc_00(int a1);
    void sub_00076D90();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
};

FirearmSoundPlayer* FirearmSoundPlayer::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00382BC0;
    ((Object*)DAT_0045398C)->sub_00077320((int)(&m_Field24));
    if (m_Field30) {
        m_Field30 = 0;
    }
    sub_00076D90();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00453918, (int)this);
    }
    return this;
}

}

