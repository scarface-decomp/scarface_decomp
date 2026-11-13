// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventVarTempo.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_01 (0x002DB7A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventVarTempo::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_3A;
        if (!sub_006F33F0(a1, m_Field10)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_00 (0x002DB7F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarTempo::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_3A;
        if (!sub_006F33D0(a1, (int)this + 16)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F94B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 bytes)
extern "C" int DAT_0085D534;

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarTempo::vfunc_03()
{
    return DAT_0085D534;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7940[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

SeqEventVarTempo* SeqEventVarTempo::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7940, (int)this);
    }
    return this;
}

}

