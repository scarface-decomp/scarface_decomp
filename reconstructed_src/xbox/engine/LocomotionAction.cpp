// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/LocomotionAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LocomotionAction::vfunc_06 (0x000E5480, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LocomotionAction::vfunc_06 (0x000E5480, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000E0490();
};

class LocomotionAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void LocomotionAction::vfunc_06()
{
    m_Field08->sub_000E0490();
}

// ============================================================================
// [VERIFIED] LocomotionAction::vfunc_03 (0x000E5500, 86 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LocomotionAction::vfunc_03 (Proto 0x000D32E0), which was matched first;
// its addresses and names were swapped for this function's.
// LocomotionAction::vfunc_03 (Proto 0x000E5500, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000D8D40(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003A7A24[];
extern "C" void __cdecl sub_00027600(int);

class LocomotionAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LocomotionAction* vfunc_03(int a1);
    void sub_000217F0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

LocomotionAction* LocomotionAction::vfunc_03(int a1)
{
    int t2, t4;

    *(int*)this = (int)DAT_003A7A24;
    m_Field10->sub_000D8D40(0);
    t2 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t2)->vfunc_01();
        m_Field0C = 0;
    }
    t4 = m_Field08;
    if (m_Field08) {
        ((Object*)t4)->vfunc_01();
        m_Field08 = 0;
    }
    sub_000217F0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

