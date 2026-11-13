// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIConditionGameTimeIsAtLeast.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionGameTimeIsAtLeast::vfunc_03 (0x00121EE0, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionSetSharedIntToRandom::vfunc_00 (0x00121540), which was matched first;
// its addresses and names were swapped for this function's.
// AIConditionGameTimeIsAtLeast::vfunc_03 (0x00121EE0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_001204E0();
};

extern "C" char DAT_0039E22C[];
extern "C" void __cdecl sub_00027600(int);

class AIConditionGameTimeIsAtLeast
{
public:
    virtual AIConditionGameTimeIsAtLeast* vfunc_03(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

AIConditionGameTimeIsAtLeast* AIConditionGameTimeIsAtLeast::vfunc_03(int a1)
{
    m_Field08.sub_001204E0();
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

