// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionBroadcastStimulus.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionBroadcastStimulus::vfunc_00 (0x00105DD0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionBroadcastStimulus::vfunc_00 (Proto 0x00105DD0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00105140();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionBroadcastStimulus
{
public:
    virtual AIActionBroadcastStimulus* vfunc_00(int a1);
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

AIActionBroadcastStimulus* AIActionBroadcastStimulus::vfunc_00(int a1)
{
    m_Field14.sub_00105140();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

