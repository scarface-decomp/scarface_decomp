// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SeqEventLogicRepeat.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_01 (0x002DCCF0, 109 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicRepeat::vfunc_01 (PC 0x006FA8E0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x002DCCF0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqEventLogicRepeat::vfunc_01 (PC 0x002DCCF0, 109 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D6340(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_002D6A20(int);
    bool sub_002D6DA0(int);
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
};

int SeqEventLogicRepeat::vfunc_01(int a1)
{
    int r_ebp, r_ebx;

    r_ebp = (unsigned char)m_Field10;
    if (m_Field10 == 255) {
        r_ebp |= -1;
    }
    r_ebx = (unsigned char)m_Field11;
    if (m_Field11 == 255) {
        r_ebx |= -1;
    }
    if (sub_002D6A20(a1)) {
        if (!sub_002D6DA0(a1)) goto L_64;
        if (!sub_002D6340(a1, r_ebp)) goto L_64;
        if (!sub_002D6340(a1, r_ebx)) goto L_64;
        return 1;
    }
L_64:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_04 (0x002DCEB0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_04 (0x002DCEB0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00464A70[];
extern "C" void __cdecl sub_002D6F30(void);
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual SeqEventLogicRepeat* vfunc_04(int a1);
};

SeqEventLogicRepeat* SeqEventLogicRepeat::vfunc_04(int a1)
{
    sub_002D6F30();
    if (a1 & 1) {
        sub_002CF980((int)DAT_00464A70, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_03 (0x002DCEE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (0x002D8D80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_03 (0x002DCEE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C04F0;

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventLogicRepeat::vfunc_03()
{
    return DAT_004C04F0;
}

}

