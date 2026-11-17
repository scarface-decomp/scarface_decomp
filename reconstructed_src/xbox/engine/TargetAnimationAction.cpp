// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TargetAnimationAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TargetAnimationAction::vfunc_08 (0x000E6710, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as TargetAnimationAction::vfunc_07 (Proto 0x000D42D0), which was matched first;
// its addresses and names were swapped for this function's.
// TargetAnimationAction::vfunc_08 (Proto 0x000E6710, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_0019D3D0();
};

struct Field0C
{
    void sub_000D8550();
};

struct Field14
{
    void sub_00285150(int, int);
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
    virtual void vfunc_08();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14* m_Field14; // +0x14
};

void TargetAnimationAction::vfunc_08()
{
    m_Field14->sub_00285150(0, 0);
    if (m_Field08->sub_0019D3D0()) {
        m_Field0C->sub_000D8550();
        return;
    }
}

// ============================================================================
// [VERIFIED] TargetAnimationAction::vfunc_06 (0x000E6740, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TargetAnimationAction::vfunc_06 (0x000E6740, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field18
{
    void sub_000E6E90();
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
    char m_pad04[0x14];
    Field18* m_Field18; // +0x18
};

void TargetAnimationAction::vfunc_06()
{
    m_Field18->sub_000E6E90();
}

