// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqEventConditionElse.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventConditionElse::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventConditionElse::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7680
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 bytes)
extern "C" int DAT_0085D504;

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventConditionElse::vfunc_03()
{
    return DAT_0085D504;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7334[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual SeqEventConditionElse* vfunc_04(int a1);
};

SeqEventConditionElse* SeqEventConditionElse::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7334, (int)this);
    }
    return this;
}

}

