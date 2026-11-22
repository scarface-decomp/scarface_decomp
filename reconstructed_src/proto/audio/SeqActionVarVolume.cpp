// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqActionVarVolume.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_00 (0x002A6EC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolume::vfunc_00 (0x002A6EC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9F28[];
extern "C" char DAT_004911CC[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class SeqActionVarVolume
{
public:
    virtual SeqActionVarVolume* vfunc_00(int a1);
};

SeqActionVarVolume* SeqActionVarVolume::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9F28;
    if (a1 & 1) {
        sub_002935D0((int)DAT_004911CC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_06 (0x002A7060, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Writes the address 48 bytes into this action's data into the object it is given.
// ============================================================================
// bin: proto
// va: 0x002A7060
// what: Writes the address 48 bytes into this action's data into the object it is given.
// tool: Claude Opus 5.5 (transplanted from pc:0x006F9310, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarVolume::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 48;
    *(int*)(*(int*)(a1 + 4) + 36) = m_Field04 + 48;
}

}

