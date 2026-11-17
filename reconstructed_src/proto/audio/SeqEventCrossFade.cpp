// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventCrossFade.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_00 (0x002A9F40, 192 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventCrossFade::vfunc_00 (Proto 0x002A9F40, 192 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field60
{
    bool sub_002AFAD0(int);
};

extern "C" bool __cdecl sub_002928C0(int, int);
extern "C" bool __cdecl sub_00293F70(int, int);
extern "C" bool __cdecl sub_0029B830(int, int);
extern "C" bool __cdecl sub_0029BA30(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x8];
    int m_Field50; // +0x50
    char m_pad54[0xC];
    Field60 m_Field60; // +0x60
};

int SeqEventCrossFade::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_0029BA30(a1, (int)(&m_Field30))) goto L_B9;
        if (!sub_0029BA30(a1, (int)(&m_Field34))) goto L_B9;
        if (!sub_0029BA30(a1, (int)(&m_Field38))) goto L_B9;
        if (!sub_0029BA30(a1, (int)(&m_Field3C))) goto L_B9;
        if (!sub_0029B830(a1, (int)(&m_Field40))) goto L_B9;
        if (!sub_0029B830(a1, (int)(((char*)this + 0x41)))) goto L_B9;
        if (!sub_002928C0(a1, (int)(&m_Field44))) goto L_B9;
        if (!sub_00293F70(a1, (int)(&m_Field50))) goto L_B9;
        if (!m_Field60.sub_002AFAD0(a1)) goto L_B9;
        return 1;
    }
L_B9:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_05 (0x002AA0D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_05 (0x002AA0D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491364;

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventCrossFade::vfunc_05()
{
    return DAT_00491364;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_06 (0x002AA0E0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_06 (0x002AA0E0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491368[];
extern "C" void __cdecl sub_002AA110(void);
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual SeqEventCrossFade* vfunc_06(int a1);
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_06(int a1)
{
    sub_002AA110();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491368, (int)this);
    }
    return this;
}

}

