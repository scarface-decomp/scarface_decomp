// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TutorialManager.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TutorialManager::vfunc_00 (0x00233030, 75 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TutorialManager::vfunc_00 (0x00233030, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EBA00();
};

extern "C" char DAT_003D3388[];
extern "C" char DAT_003D3390[];
extern "C" int DAT_00492910;
extern "C" void __cdecl sub_00027600(int);
extern "C" int __stdcall sub_000EB680(int, int);

class TutorialManager
{
public:
    virtual TutorialManager* vfunc_00(int a1);
    void sub_000EA330();
    int m_Field04; // +0x04
};

TutorialManager* TutorialManager::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D3390;
    m_Field04 = (int)DAT_003D3388;
    ((Object*)sub_000EB680(226, (int)(&m_Field04)))->sub_000EBA00();
    DAT_00492910 = -0x22222223;
    sub_000EA330();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

