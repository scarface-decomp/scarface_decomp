// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, ai/AIActionRepeatIndefinite.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionRepeatIndefinite::vfunc_03 (0x0011FC60, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionRepeatIndefinite::vfunc_03 (0x0011FC60, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0011E1A0();
    int sub_0011E1B0();
};

class AIActionRepeatIndefinite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIActionRepeatIndefinite::vfunc_03()
{
    if (!(m_Field0C & 1)) {
        if (m_Field08->sub_0011E1B0() != 2) goto L_1E;
        m_Field08->sub_0011E1A0();
    }
L_1E:
    return 1;
}

// ============================================================================
// [VERIFIED] AIActionRepeatIndefinite::vfunc_00 (0x00120020, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionRepeatIndefinite::vfunc_00 (0x00120020, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0011FBB0(void);
extern "C" void __cdecl sub_00027600(int);

class AIActionRepeatIndefinite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIActionRepeatIndefinite* vfunc_00(int a1);
};

AIActionRepeatIndefinite* AIActionRepeatIndefinite::vfunc_00(int a1)
{
    sub_0011FBB0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

