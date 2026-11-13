// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SubtitleFlowClient.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SubtitleManager::SubtitleFlowClient::vfunc_01 (0x000CAF80, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SubtitleManager::SubtitleFlowClient::vfunc_01 (0x000CAF80, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002A9290(...);

namespace SubtitleManager {

class SubtitleFlowClient
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    void sub_000CA860();
    void sub_000CAB70(int, int);
};

int SubtitleFlowClient::vfunc_01(int a1, int a2)
{
    sub_002A9290(6);
    if (a2 == 32) {
        sub_000CA860();
        sub_000CAB70(100, 200);
    }
    sub_002A9290();
    return 1;
}

}

// ============================================================================
// [VERIFIED] SubtitleManager::SubtitleFlowClient::vfunc_03 (0x000CAFC0, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SubtitleManager::SubtitleFlowClient::vfunc_03 (0x000CAFC0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002A9290(...);

namespace SubtitleManager {

class SubtitleFlowClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2);
    void sub_000CA860();
    void sub_000CAB70(int, int);
};

int SubtitleFlowClient::vfunc_03(int a1, int a2)
{
    sub_002A9290(6);
    if (a2 == 32) {
        sub_000CA860();
        sub_000CAB70(5, 20);
    }
    sub_002A9290();
    return 1;
}

}

// ============================================================================
// [VERIFIED] SubtitleManager::SubtitleFlowClient::vfunc_00 (0x000CB620, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundFlowClient::vfunc_00 (0x00078EE0), which was matched first;
// its addresses and names were swapped for this function's.
// SubtitleManager::SubtitleFlowClient::vfunc_00 (0x000CB620, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5C10[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000CA860(void);

namespace SubtitleManager {

class SubtitleFlowClient
{
public:
    virtual SubtitleFlowClient* vfunc_00(int a1);
    void sub_000EA330();
};

SubtitleFlowClient* SubtitleFlowClient::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A5C10;
    sub_000CA860();
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

