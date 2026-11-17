// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TargetAnimationAction.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 5 functions matched (20.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TargetAnimationAction::vfunc_07 (0x000D42D0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TargetAnimationAction::vfunc_07 (Proto 0x000D42D0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_0015E330();
};

struct Field0C
{
    void sub_000C6A20();
};

struct Field14
{
    void sub_00241390(int, int);
};

class TargetAnimationAction
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
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14* m_Field14; // +0x14
};

void TargetAnimationAction::vfunc_07()
{
    m_Field14->sub_00241390(0, 0);
    if (m_Field08->sub_0015E330()) {
        m_Field0C->sub_000C6A20();
        return;
    }
}

