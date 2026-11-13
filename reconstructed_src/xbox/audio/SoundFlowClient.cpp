// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/SoundFlowClient.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundManager::SoundFlowClient::vfunc_00 (0x00078EE0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::SoundFlowClient::vfunc_00 (0x00078EE0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A32C4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000780C0(void);

namespace SoundManager {

class SoundFlowClient
{
public:
    virtual SoundFlowClient* vfunc_00(int a1);
    void sub_000EA330();
};

SoundFlowClient* SoundFlowClient::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A32C4;
    sub_000780C0();
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] SoundManager::SoundFlowClient::vfunc_02 (0x00078F10, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SoundManager::SoundFlowClient::vfunc_02 (0x00078F10, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000789F0(int);
extern "C" void __cdecl sub_002A9290(...);
extern "C" void __cdecl sub_002D4420(void);

namespace SoundManager {

class SoundFlowClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void SoundFlowClient::vfunc_02(int a1, int a2, int a3)
{
    sub_002A9290(12);
    if (a3 == 1) {
        sub_002D4420();
        sub_002A9290();
        return;
    }
    sub_000789F0(a1);
    sub_002A9290();
}

}

