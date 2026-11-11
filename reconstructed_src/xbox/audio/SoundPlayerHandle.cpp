// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SoundPlayerHandle.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A32BC[];
extern "C" char DAT_0042262C[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace SoundManager {

class SoundPlayerHandle
{
public:
    virtual SoundPlayerHandle* vfunc_00(int a1);
};

SoundPlayerHandle* SoundPlayerHandle::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A32BC;
    if (a1 & 1) {
        sub_002CF980((int)DAT_0042262C, (int)this);
    }
    return this;
}

}

