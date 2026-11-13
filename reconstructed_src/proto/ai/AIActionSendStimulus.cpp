// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionSendStimulus.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSendStimulus::vfunc_00 (0x00105C90, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimUsingUID::vfunc_00 (0x00121240), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSendStimulus::vfunc_00 (0x00105C90, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_00105140();
};

extern "C" char DAT_0038C664[];
extern "C" void __cdecl sub_00025160(int);

class AIActionSendStimulus
{
public:
    virtual AIActionSendStimulus* vfunc_00(int a1);
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

AIActionSendStimulus* AIActionSendStimulus::vfunc_00(int a1)
{
    m_Field10.sub_00105140();
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

