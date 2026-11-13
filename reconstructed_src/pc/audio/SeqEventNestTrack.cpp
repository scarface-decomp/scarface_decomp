// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventNestTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventNestTrack::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ECC20(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a value kept in the game's data.
// ============================================================================
// bin: pc
// va: 0x006F6960
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 bytes)
extern "C" int DAT_0085D4F0;

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventNestTrack::vfunc_03()
{
    return DAT_0085D4F0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F6FE8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventNestTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventNestTrack* SeqEventNestTrack::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6FE8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int SeqEventNestTrack::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006ECBD0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

