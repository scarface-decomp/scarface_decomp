// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventNestTrack.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_05 (0x002A0690, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_05 (0x002A0690, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490F30;

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventNestTrack::vfunc_05()
{
    return DAT_00490F30;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_06 (0x002A06A0, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_06 (Proto 0x002A06A0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_00291040();
};

extern "C" char DAT_00490F38[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventNestTrack* vfunc_06(int a1);
    void sub_0029E700();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
};

SeqEventNestTrack* SeqEventNestTrack::vfunc_06(int a1)
{
    m_Field30.sub_00291040();
    sub_0029E700();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00490F38, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_01 (0x002A3D50, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_01 (Proto 0x002A3D50, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00292810(int, int);
extern "C" bool __stdcall sub_0029E730(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int SeqEventNestTrack::vfunc_01(int a1)
{
    if (sub_0029E730(a1)) {
        if (!sub_00292810(a1, (int)this + 48)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_00 (0x002A4700, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventNestTrack::vfunc_00 (Proto 0x002A4700, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002928C0(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual int vfunc_00(int a1);
};

int SeqEventNestTrack::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_002928C0(a1, (int)this + 48)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

