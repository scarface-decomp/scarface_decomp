// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventWaitBeat.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_00 (0x002A4240, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventWaitBeat::vfunc_00 (Proto 0x002A4240, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    bool sub_002AFAD0(int);
};

extern "C" bool __cdecl sub_00293F70(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0x7];
    int m_Field38; // +0x38
};

int SeqEventWaitBeat::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_00293F70(a1, (int)(&m_Field38))) goto L_3A;
        if (!m_Field30.sub_002AFAD0(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_05 (0x002A43D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_05 (0x002A43D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491060;

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventWaitBeat::vfunc_05()
{
    return DAT_00491060;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_06 (0x002A43E0, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventWaitBeat::vfunc_06 (Proto 0x002A43E0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_002AFC20();
};

struct Field3C
{
    void sub_00291040();
};

extern "C" char DAT_00491064[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventWaitBeat* vfunc_06(int a1);
    void sub_0029E700();
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0xB];
    Field3C m_Field3C; // +0x3C
};

SeqEventWaitBeat* SeqEventWaitBeat::vfunc_06(int a1)
{
    m_Field3C.sub_00291040();
    m_Field30.sub_002AFC20();
    sub_0029E700();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491064, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_01 (0x002A44C0, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventWaitBeat::vfunc_01 (Proto 0x002A44C0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    bool sub_002AFA60(int);
};

extern "C" bool __cdecl sub_00292810(int, int);
extern "C" bool __stdcall sub_0029E730(int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x2C];
    Field30 m_Field30; // +0x30
    char m_pad31[0xB];
    int m_Field3C; // +0x3C
};

int SeqEventWaitBeat::vfunc_01(int a1)
{
    if (sub_0029E730(a1)) {
        if (!sub_00292810(a1, (int)(&m_Field3C))) goto L_3A;
        if (!m_Field30.sub_002AFA60(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

