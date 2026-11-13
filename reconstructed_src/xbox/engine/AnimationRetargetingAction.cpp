// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AnimationRetargetingAction.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 6 functions matched (16.67%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AnimationRetargetingAction::vfunc_08 (0x000E2BA0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AnimationRetargetingAction::vfunc_08 (0x000E2BA0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000D0070(int);
    int sub_000D3C80(int);
};

class AnimationRetargetingAction
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
    virtual void vfunc_08();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x2C];
    int m_Field3C; // +0x3C
    char m_pad40[0x20];
    int m_Field60; // +0x60
    char m_pad64[0x9];
    bool m_Field6D; // +0x6D
    char m_pad6E[0x1];
    bool m_Field6F; // +0x6F
};

void AnimationRetargetingAction::vfunc_08()
{
    int r_eax;

    r_eax = m_Field6D;
    if ((unsigned char)r_eax) {
        r_eax = (int)(&m_Field3C);
        m_Field0C->sub_000D0070((int)(&m_Field3C));
    }
    r_eax = m_Field6F;
    if ((unsigned char)r_eax) {
        r_eax = m_Field0C->sub_000D3C80((int)(&m_Field60));
    }
}

