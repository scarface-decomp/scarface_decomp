// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventChannelSends.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F71F0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 bytes)
extern "C" int DAT_0085D4FC;

namespace audio {

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSends::vfunc_03()
{
    return DAT_0085D4FC;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F71F8[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

SeqEventChannelSends* SeqEventChannelSends::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F71F8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSends::vfunc_00 (0x002D9630), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006EC1E0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x104];
    int m_Field108; // +0x108
};

int SeqEventChannelSends::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field108))) goto L_41;
        if (!sub_006EC1E0(a1, (int)this + 8)) goto L_41;
        return 1;
    }
L_41:
    return 0;
}

}

