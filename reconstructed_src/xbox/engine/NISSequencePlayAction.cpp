// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISSequencePlayAction.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_08 (0x0017EDF0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISSequencePlayAction::vfunc_08 (0x0017EDF0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002BF820();
};

extern "C" int DAT_0048A218;

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int NISSequencePlayAction::vfunc_08()
{
    int r_eax;

    r_eax = ((Object*)DAT_0048A218)->sub_002BF820();
    *(int*)(r_eax + 508) = 0;
    r_eax = m_Field10;
    if (r_eax) {
        *(int*)(r_eax + 36) -= 1;
        m_Field10 = 0;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_03 (0x00180DB0, 70 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISSequencePlayAction::vfunc_03 (Proto 0x0015F860), which was matched first;
// its addresses and names were swapped for this function's.
// NISSequencePlayAction::vfunc_03 (Proto 0x00180DB0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003B6344[];
extern "C" char DAT_003B634C[];
extern "C" void __cdecl sub_00027600(int);

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISSequencePlayAction* vfunc_03(int a1);
    void sub_000217F0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

NISSequencePlayAction* NISSequencePlayAction::vfunc_03(int a1)
{
    int t1, t3;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003B634C;
    m_Field08 = (int)DAT_003B6344;
    ((Object*)t1)->vfunc_01();
    t3 = m_Field10;
    if (m_Field10) {
        *(int*)(t3 + 36) -= 1;
        m_Field10 = 0;
    }
    sub_000217F0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] NISSequencePlayAction::vfunc_04 (0x0019D3D0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISSequencePlayAction::vfunc_04 (Proto 0x0015E330), which was matched first;
// its addresses and names were swapped for this function's.
// NISSequencePlayAction::vfunc_04 (Proto 0x0019D3D0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISSequencePlayAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
    char m_pad04[0x10];
    bool m_Field14; // +0x14
};

bool NISSequencePlayAction::vfunc_04()
{
    return m_Field14;
}

