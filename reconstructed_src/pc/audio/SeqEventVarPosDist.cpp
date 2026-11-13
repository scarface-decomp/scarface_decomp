// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventVarPosDist.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F79E4[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual SeqEventVarPosDist* vfunc_04(int a1);
};

SeqEventVarPosDist* SeqEventVarPosDist::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F79E4, (int)this);
    }
    return this;
}

}

