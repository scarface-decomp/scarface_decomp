// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/PauseMenuPageCheatItem.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PauseMenuPageRewards::PauseMenuPageCheatItem::vfunc_04 (0x001CD050, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls virtual method slot 0 on the embedded member object at +0x44.
// ============================================================================
// bin: xb
// va: 0x001CD050
// what: Calls virtual method slot 0 on the embedded member object at +0x44.
// tool: Gemini 4 Neon

struct Field44
{
    virtual void vfunc_00();
    void Call00() { vfunc_00(); }
};

namespace PauseMenuPageRewards {

class PauseMenuPageCheatItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
};

void PauseMenuPageCheatItem::vfunc_04()
{
    m_Field44.Call00();
}

}

