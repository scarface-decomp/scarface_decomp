// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventVarVolumeRand.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_01 (0x002DB360, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarVolumeRand::vfunc_01 (0x002DB360, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002D6340(int, int);
extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void SeqEventVarVolumeRand::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        sub_002D6340(a1, m_Field08);
    }
    sub_002D6340(a1, m_Field0C);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_00 (0x002DB3A0, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventVarVolumeRand::vfunc_00 (0x002DB3A0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D6320(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolumeRand::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!sub_002D6320(a1, (int)(&m_Field08))) goto L_3E;
        if (!sub_002D6320(a1, (int)this + 12)) goto L_3E;
        return 1;
    }
L_3E:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_03 (0x002DB420, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_03 (0x002DB420, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04D0;

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolumeRand::vfunc_03()
{
    return DAT_004C04D0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_04 (0x002DB430, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_04 (0x002DB430, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00464570[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual SeqEventVarVolumeRand* vfunc_04(int a1);
};

SeqEventVarVolumeRand* SeqEventVarVolumeRand::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464570, (int)this);
    }
    return this;
}

}

