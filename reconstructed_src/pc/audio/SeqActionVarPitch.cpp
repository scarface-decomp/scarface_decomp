// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SeqActionVarPitch.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7B44[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPitch
{
public:
    virtual SeqActionVarPitch* vfunc_00(int a1);
};

SeqActionVarPitch* SeqActionVarPitch::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B44, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionVarPitch::vfunc_06 (0x002DBF00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarPitch
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

void SeqActionVarPitch::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 8;
    *(int*)(*(int*)(a1 + 4) + 36) = m_Field04 + 8;
}

}

