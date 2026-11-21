// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventCrossFade.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_00 (0x006FB040, 192 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_00 (0x002DD430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_00 (0x006FB040, 192 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    bool sub_00700D90(int);
};

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006F3300(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x8];
    int m_Field28; // +0x28
    Field2C m_Field2C; // +0x2C
};

int SeqEventCrossFade::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field10))) goto L_B9;
        if (!sub_006F33D0(a1, (int)(&m_Field14))) goto L_B9;
        if (!sub_006F3300(a1, (int)(&m_Field18))) goto L_B9;
        if (!sub_006F3300(a1, (int)(((char*)this + 0x19)))) goto L_B9;
        if (!sub_006ECC20(a1, (int)(&m_Field1C))) goto L_B9;
        if (!sub_006ED500(a1, (int)(&m_Field28))) goto L_B9;
        if (!m_Field2C.sub_00700D90(a1)) goto L_B9;
        return 1;
    }
L_B9:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FB240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 bytes)
extern "C" int DAT_0085D558;

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCrossFade::vfunc_03()
{
    return DAT_0085D558;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_04 (0x002DD640), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_006EBBD0();
};

struct Field2C
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7E38[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCrossFade* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0xF];
    Field2C m_Field2C; // +0x2C
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_04(int a1)
{
    m_Field2C.sub_00700EE0();
    m_Field1C.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E38, (int)this);
    }
    return this;
}

}

