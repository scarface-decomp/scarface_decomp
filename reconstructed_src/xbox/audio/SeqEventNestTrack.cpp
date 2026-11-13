// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventNestTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_01 (0x002D8D00, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_01 (0x002D8D00, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CEFF0(int, int);
extern "C" bool __stdcall sub_002D6A20(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int SeqEventNestTrack::vfunc_01(int a1)
{
    if (sub_002D6A20(a1)) {
        if (!sub_002CEFF0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_00 (0x002D8D40, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_00 (0x002D8D40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002CF040(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventNestTrack::vfunc_00(int a1)
{
    if (sub_002D6A00(a1)) {
        if (!sub_002CF040(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_03 (0x002D8D80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_03 (0x002D8D80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C0494;

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
    return DAT_004C0494;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_04 (0x002D8D90, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_04 (0x002D8D90, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_002CE560();
};

extern "C" char DAT_00463D5C[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventNestTrack* vfunc_04(int a1);
    void sub_002D69E0();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventNestTrack* SeqEventNestTrack::vfunc_04(int a1)
{
    m_Field08.sub_002CE560();
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00463D5C, (int)this);
    }
    return this;
}

}

