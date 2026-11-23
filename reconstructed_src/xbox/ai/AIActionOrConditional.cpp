// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionOrConditional.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionOrConditional::vfunc_05 (0x0011FB00, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIActionOrConditional::vfunc_05 (Proto 0x00104710), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionOrConditional::vfunc_05 (Proto 0x0011FB00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AIActionOrConditional
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x14];
    bool m_Field18; // +0x18
};

void AIActionOrConditional::vfunc_05()
{
    m_Field18 = false;
}

// ============================================================================
// [VERIFIED] AIActionOrConditional::vfunc_00 (0x001201A0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionOrConditional's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AIActionOrConditional::vfunc_00 (Proto 0x00104E90), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionOrConditional::vfunc_00 (Proto 0x001201A0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_000EF6A0();
};

extern "C" void __cdecl sub_00027600(int);

class AIActionOrConditional
{
public:
    virtual AIActionOrConditional* vfunc_00(int a1);
    void sub_0011F6A0();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

AIActionOrConditional* AIActionOrConditional::vfunc_00(int a1)
{
    m_Field14.sub_000EF6A0();
    sub_0011F6A0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

