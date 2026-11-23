// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEventLogicRepeat.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_01 (0x002A9520, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x002A9520
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqEventLogicRepeat::vfunc_01 (Proto 0x002A9520, 109 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0029B950(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_0029E730(int);
    bool sub_0029ECF0(int);
    char m_pad04[0x34];
    bool m_Field38; // +0x38
    bool m_Field39; // +0x39
};

int SeqEventLogicRepeat::vfunc_01(int a1)
{
    int r_ebp, r_ebx;

    r_ebp = (unsigned char)m_Field38;
    if (m_Field38 == 255) {
        r_ebp |= -1;
    }
    r_ebx = (unsigned char)m_Field39;
    if (m_Field39 == 255) {
        r_ebx |= -1;
    }
    if (sub_0029E730(a1)) {
        if (!sub_0029ECF0(a1)) goto L_64;
        if (!sub_0029B950(a1, r_ebp)) goto L_64;
        if (!sub_0029B950(a1, r_ebx)) goto L_64;
        return 1;
    }
L_64:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_06 (0x002A9740, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_06 (0x002A9740, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00491308[];
extern "C" void __cdecl sub_0029EEB0(void);
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual SeqEventLogicRepeat* vfunc_06(int a1);
};

SeqEventLogicRepeat* SeqEventLogicRepeat::vfunc_06(int a1)
{
    sub_0029EEB0();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491308, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_05 (0x002A9770, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dFBEffectsShader::vfunc_04 (0x0029F440), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_05 (0x002A9770, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491304;

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_05();
};

int SeqEventLogicRepeat::vfunc_05()
{
    return DAT_00491304;
}

}

