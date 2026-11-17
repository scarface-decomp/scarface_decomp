// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventClip.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_00 (0x002AAAB0, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventClip::vfunc_00 (Proto 0x002AAAB0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field38
{
    bool sub_00299490(int);
};

extern "C" bool __cdecl sub_0029B830(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventClip
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    Field38 m_Field38; // +0x38
};

int SeqEventClip::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_0029B830(a1, (int)(&m_Field30))) goto L_3A;
        if (!m_Field38.sub_00299490(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_05 (0x002AAD00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventClip::vfunc_05 (0x002AAD00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491390;

namespace audio {

class SeqEventClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventClip::vfunc_05()
{
    return DAT_00491390;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_06 (0x002AAD10, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventClip::vfunc_06 (Proto 0x002AAD10, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field40
{
    void sub_00291040();
};

extern "C" char DAT_00491398[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventClip* vfunc_06(int a1);
    void sub_0029E700();
    char m_pad04[0x3C];
    Field40 m_Field40; // +0x40
};

SeqEventClip* SeqEventClip::vfunc_06(int a1)
{
    m_Field40.sub_00291040();
    sub_0029E700();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491398, (int)this);
    }
    return this;
}

}

