// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventLogicOr.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_01 (0x002DD0A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field10)) goto L_39;
        if (!sub_006F5AC0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_00 (0x002DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field10))) goto L_39;
        if (!sub_006F5A60(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7D94[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual SeqEventLogicOr* vfunc_04(int a1);
};

SeqEventLogicOr* SeqEventLogicOr::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D94, (int)this);
    }
    return this;
}

}

