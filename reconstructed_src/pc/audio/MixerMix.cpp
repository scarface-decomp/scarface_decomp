// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/MixerMix.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_00 (0x006EDFF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EDFF0
// what: 
// tool: the portal's starter code (no AI)

// audio::MixerMix::vfunc_00 (PC 0x006EDFF0, 5 bytes)
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
// [VERIFIED] audio::MixerMix::vfunc_01 (0x006EE000, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EE000
// what: 
// tool: the portal's starter code (no AI)

// audio::MixerMix::vfunc_01 (PC 0x006EE000, 23 bytes)
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
        ((void (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax += -1;
    *(int*)(r_ecx + 72) = r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_03 (0x006EE800, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::MixerMix::vfunc_03 (0x006EE800, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F681C[];
extern "C" void __cdecl sub_006EE790(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class MixerMix
{
public:
    virtual MixerMix* vfunc_03(int a1);
};

MixerMix* MixerMix::vfunc_03(int a1)
{
    sub_006EE790();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F681C, (int)this);
    }
    return this;
}

}

