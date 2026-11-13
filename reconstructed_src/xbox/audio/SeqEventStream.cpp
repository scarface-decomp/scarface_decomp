// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventStream.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_01 (0x002DBFF0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_01 (0x002DBFF0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_0014A270(int);
};

extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        if (!m_Field08.sub_0014A270(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_00 (0x002DC020, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_00 (0x002DC020, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_002D6060(int);
};

extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!m_Field08.sub_002D6060(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_03 (0x002DC200, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_03 (0x002DC200, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04E8;

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStream::vfunc_03()
{
    return DAT_004C04E8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_04 (0x002DC210, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_04 (0x002DC210, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00464928[];
extern "C" void __cdecl sub_002D69E0(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventStream
{
public:
    virtual SeqEventStream* vfunc_04(int a1);
};

SeqEventStream* SeqEventStream::vfunc_04(int a1)
{
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464928, (int)this);
    }
    return this;
}

}

