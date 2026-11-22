// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionSendStimulus.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionSendStimulus::vfunc_08 (0x00120CB0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes the value at +0x8 to sub_000CA2B0 and returns its result.
// ============================================================================
// bin: xb
// va: 0x00120CB0
// what: Passes the value at +0x8 to sub_000CA2B0 and returns its result.
// tool: Claude Opus 5.5 (generated from the shape 'call with a field', checked on decomp.me preset 266 by example)
extern "C" int __cdecl sub_000CA2B0(int value);

class Class_00120CB0
{
public:
    int sub_00120CB0();
    char m_pad00[0x8];
    int m_Field8; // +0x8
};

int Class_00120CB0::sub_00120CB0()
{
    return sub_000CA2B0(m_Field8);
}

// ============================================================================
// [VERIFIED] AIActionSendStimulus::vfunc_00 (0x00121280, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionPlayAnimUsingUID::vfunc_00 (0x00121240), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionSendStimulus::vfunc_00 (0x00121280, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_001204E0();
};

extern "C" char DAT_003AAAC8[];
extern "C" void __cdecl sub_00027600(int);

class AIActionSendStimulus
{
public:
    virtual AIActionSendStimulus* vfunc_00(int a1);
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

AIActionSendStimulus* AIActionSendStimulus::vfunc_00(int a1)
{
    m_Field10.sub_001204E0();
    *(int*)this = (int)DAT_003AAAC8;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

