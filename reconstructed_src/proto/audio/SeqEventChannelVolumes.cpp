// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventChannelVolumes.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_05 (0x002A59E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelVolumes::vfunc_05 (0x002A59E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491130;

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventChannelVolumes::vfunc_05()
{
    return DAT_00491130;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_06 (0x002A59F0, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventChannelVolumes::vfunc_06 (Proto 0x002A59F0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
{
    void sub_00291040();
};

extern "C" char DAT_00491134[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEventChannelVolumes* vfunc_06(int a1);
    void sub_0029E700();
    char m_pad04[0x44];
    Field48 m_Field48; // +0x48
};

SeqEventChannelVolumes* SeqEventChannelVolumes::vfunc_06(int a1)
{
    m_Field48.sub_00291040();
    sub_0029E700();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491134, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_01 (0x002A6030, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventChannelVolumes::vfunc_01 (Proto 0x002A6030, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00292810(int, int);
extern "C" bool __cdecl sub_0029B950(int, int);
extern "C" bool __stdcall sub_0029E730(int);
extern "C" bool __cdecl sub_002A5E10(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    int m_Field48; // +0x48
};

int SeqEventChannelVolumes::vfunc_01(int a1)
{
    if (sub_0029E730(a1)) {
        if (!sub_0029B950(a1, m_Field40)) goto L_4F;
        if (!sub_00292810(a1, (int)(&m_Field48))) goto L_4F;
        if (!sub_002A5E10(a1, (int)this + 48)) goto L_4F;
        return 1;
    }
L_4F:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_00 (0x002A6160, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventChannelVolumes::vfunc_00 (Proto 0x002A6160, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00293F70(int, int);
extern "C" bool __cdecl sub_0029BA30(int, int);
extern "C" bool __stdcall sub_0029E710(int);
extern "C" bool __cdecl sub_002A5E80(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

int SeqEventChannelVolumes::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_0029BA30(a1, (int)(&m_Field40))) goto L_4F;
        if (!sub_00293F70(a1, (int)(&m_Field44))) goto L_4F;
        if (!sub_002A5E80(a1, (int)this + 48)) goto L_4F;
        return 1;
    }
L_4F:
    return 0;
}

}

