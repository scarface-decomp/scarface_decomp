// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDDistanceBubbleRestoreData.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDDistanceBubbleRestoreData::vfunc_00 (0x0018E490, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0018E490
// what: 
// tool: the portal's starter code (no AI)

// HUDDistanceBubbleRestoreData::vfunc_00 (Proto 0x0018E490, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D8B4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016E0D0(void);

class HUDDistanceBubbleRestoreData
{
public:
    virtual HUDDistanceBubbleRestoreData* vfunc_00(int a1);
    char m_pad04[0x4];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

HUDDistanceBubbleRestoreData* HUDDistanceBubbleRestoreData::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_0039D8B4;
    m_Field10 = 0.0f;
    m_Field0C = 0.0f;
    m_Field08 = 0.0f;
    sub_0016E0D0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

