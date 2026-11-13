// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/MixerMix.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_02 (0x001C8800, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::MixerMix::vfunc_02 (0x001C8800, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

int MixerMix::vfunc_02()
{
    return m_Field48;
}

}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_00 (0x002D0570, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::MixerMix::vfunc_00 (0x002D0570, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    char m_pad04[0x44];
    int m_Field48; // +0x48
};

void MixerMix::vfunc_00()
{
    m_Field48 += 1;
}

}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_01 (0x002D0580, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::MixerMix::vfunc_01 (0x002D0580, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class MixerMix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void MixerMix::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 72);
    if (r_eax == 1) {
        r_eax = *(int*)r_ecx;
        r_eax = ((int (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax -= 1;
    *(int*)(r_ecx + 72) = r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_03 (0x002D0D70, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::MixerMix::vfunc_03 (0x002D0D70, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004634D4[];
extern "C" void __cdecl sub_002D0D00(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class MixerMix
{
public:
    virtual MixerMix* vfunc_03(int a1);
};

MixerMix* MixerMix::vfunc_03(int a1)
{
    sub_002D0D00();
    if (a1 & 1) {
        sub_002CF980((int)DAT_004634D4, (int)this);
    }
    return this;
}

}

