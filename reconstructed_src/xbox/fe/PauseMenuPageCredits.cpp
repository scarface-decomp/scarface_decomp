// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/PauseMenuPageCredits.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageCredits::vfunc_00 (0x001CB0A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PauseMenuPageCredits::vfunc_00 (0x001CB0A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00439E54[];

class PauseMenuPageCredits
{
public:
    virtual void* vfunc_00();
};

void* PauseMenuPageCredits::vfunc_00()
{
    return DAT_00439E54;
}

// ============================================================================
// [VERIFIED] PauseMenuPageCredits::vfunc_01 (0x001CB130, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PauseMenuPageCredits::vfunc_01 (0x001CB130, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldA8
{
    void sub_0018FA80();
};

extern "C" void __cdecl sub_00027600(int);

class PauseMenuPageCredits
{
public:
    virtual void vfunc_00();
    virtual PauseMenuPageCredits* vfunc_01(int a1);
    void sub_001CAA10();
    char m_pad04[0xA4];
    FieldA8 m_FieldA8; // +0xA8
};

PauseMenuPageCredits* PauseMenuPageCredits::vfunc_01(int a1)
{
    m_FieldA8.sub_0018FA80();
    sub_001CAA10();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

