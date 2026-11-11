// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/ChannelVolumeFadeBehaviour.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" char DAT_007F7750[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class ChannelVolumeFadeBehaviour
{
public:
    virtual ChannelVolumeFadeBehaviour* vfunc_00(int a1);
};

ChannelVolumeFadeBehaviour* ChannelVolumeFadeBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7750, (int)this);
    }
    return this;
}

}

