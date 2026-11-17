// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventCrossFade.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_00 (0x002DD430, 192 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCrossFade::vfunc_00 (0x002DD430, 192 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    bool sub_002E2720(int);
};

extern "C" bool __cdecl sub_002CF040(int, int);
extern "C" bool __cdecl sub_002CFAA0(int, int);
extern "C" bool __cdecl sub_002D6250(int, int);
extern "C" bool __cdecl sub_002D6320(int, int);
extern "C" bool __stdcall sub_002D6A00(int);

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
    if (sub_002D6A00(a1)) {
        if (!sub_002D6320(a1, (int)(&m_Field08))) goto L_B9;
        if (!sub_002D6320(a1, (int)(&m_Field0C))) goto L_B9;
        if (!sub_002D6320(a1, (int)(&m_Field10))) goto L_B9;
        if (!sub_002D6320(a1, (int)(&m_Field14))) goto L_B9;
        if (!sub_002D6250(a1, (int)(&m_Field18))) goto L_B9;
        if (!sub_002D6250(a1, (int)(((char*)this + 0x19)))) goto L_B9;
        if (!sub_002CF040(a1, (int)(&m_Field1C))) goto L_B9;
        if (!sub_002CFAA0(a1, (int)(&m_Field28))) goto L_B9;
        if (!m_Field2C.sub_002E2720(a1)) goto L_B9;
        return 1;
    }
L_B9:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_03 (0x002DD630, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_03 (0x002DD630, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04FC;

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
    return DAT_004C04FC;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_04 (0x002DD640, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCrossFade::vfunc_04 (0x002DD640, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_002CE560();
};

struct Field2C
{
    void sub_002E2870();
};

extern "C" char DAT_00464BB0[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCrossFade* vfunc_04(int a1);
    void sub_002D69E0();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0xF];
    Field2C m_Field2C; // +0x2C
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_04(int a1)
{
    m_Field2C.sub_002E2870();
    m_Field1C.sub_002CE560();
    sub_002D69E0();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464BB0, (int)this);
    }
    return this;
}

}

