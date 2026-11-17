// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventLogicOr.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_01 (0x002A9A10, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventLogicOr::vfunc_01 (Proto 0x002A9A10, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0029B950(int, int);
extern "C" bool __stdcall sub_0029E730(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_0029ECF0(int);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int SeqEventLogicOr::vfunc_01(int a1)
{
    if (sub_0029E730(a1)) {
        if (!sub_0029B950(a1, m_Field38)) goto L_39;
        if (!sub_0029ECF0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_00 (0x002A9A50, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEventLogicOr::vfunc_00 (Proto 0x002A9A50, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0029BA30(int, int);
extern "C" bool __stdcall sub_0029E710(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual int vfunc_00(int a1);
    bool sub_0029EBC0(int);
    char m_pad04[0x34];
    int m_Field38; // +0x38
};

int SeqEventLogicOr::vfunc_00(int a1)
{
    if (sub_0029E710(a1)) {
        if (!sub_0029BA30(a1, (int)(&m_Field38))) goto L_39;
        if (!sub_0029EBC0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_05 (0x002A9BF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_05 (0x002A9BF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491334;

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventLogicOr::vfunc_05()
{
    return DAT_00491334;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_06 (0x002A9C00, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_06 (0x002A9C00, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491338[];
extern "C" void __cdecl sub_0029EEB0(void);
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual SeqEventLogicOr* vfunc_06(int a1);
};

SeqEventLogicOr* SeqEventLogicOr::vfunc_06(int a1)
{
    sub_0029EEB0();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491338, (int)this);
    }
    return this;
}

}

