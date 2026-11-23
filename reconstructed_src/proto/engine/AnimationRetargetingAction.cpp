// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AnimationRetargetingAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AnimationRetargetingAction::vfunc_07 (0x000D0BC0, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x000D0BC0
// what: 
// tool: the portal's starter code (no AI)

// AnimationRetargetingAction::vfunc_07 (Proto 0x000D0BC0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000BF5E0(int);
    void sub_000C27D0(int);
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x64];
    bool m_Field74; // +0x74
    char m_pad75[0x3];
    int m_Field78; // +0x78
    char m_pad7C[0x1C];
    bool m_Field98; // +0x98
    char m_pad99[0x3];
    int m_Field9C; // +0x9C
};

void AnimationRetargetingAction::vfunc_07()
{
    if (m_Field74) {
        m_Field0C->sub_000BF5E0((int)(&m_Field78));
    }
    if (m_Field98) {
        m_Field0C->sub_000C27D0((int)(&m_Field9C));
    }
}

// ============================================================================
// [VERIFIED] AnimationRetargetingAction::vfunc_13 (0x0026DAC0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AnimationRetargetingAction::vfunc_14 (PC 0x006E7EA0), which was matched first;
// its addresses and names were swapped for this function's.
// AnimationRetargetingAction::vfunc_13 (PC 0x0026DAC0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int AnimationRetargetingAction::vfunc_13()
{
    return m_Field10;
}

