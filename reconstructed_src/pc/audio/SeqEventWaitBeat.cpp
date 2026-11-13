// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventWaitBeat.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventWaitBeat::vfunc_00 (0x002D9FE0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700D90(int);
};

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventWaitBeat::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field10))) goto L_3A;
        if (!m_Field08.sub_00700D90(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7470[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventWaitBeat* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventWaitBeat* SeqEventWaitBeat::vfunc_04(int a1)
{
    m_Field08.sub_00700EE0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7470, (int)this);
    }
    return this;
}

}

