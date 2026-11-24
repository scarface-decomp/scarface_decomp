// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/BlendFrameController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 18 functions matched (11.11%). NOT COMPLETE YET.
// The 16 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BlendFrameController::vfunc_15 (0x002254A0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::BlendFrameController::vfunc_15 (0x00273720), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x002254A0
// what: Returns the float at the start of the last active blend entry when the entry count at +0x1C is positive, or the default float at DAT_0037CD94.
// tool: Gemini 4 Neon

extern "C" const float DAT_0037CD94;

namespace pure3d {

struct BlendEntry_002254A0
{
    float m_Field00;
    char m_pad04[0x28];
};

class BlendFrameController
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual float vfunc_15();
    char m_pad04[0x18];
    unsigned int m_Count; // +0x1C
    BlendEntry_002254A0 m_Entries[4]; // +0x20
};

float BlendFrameController::vfunc_15()
{
    if (m_Count > 0)
        return m_Entries[m_Count - 1].m_Field00;
    return DAT_0037CD94;
}

}

// ============================================================================
// [VERIFIED] pure3d::BlendFrameController::vfunc_03 (0x002263D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::BlendFrameController::vfunc_03 (0x002263D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00225E50(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class BlendFrameController
{
public:
    virtual BlendFrameController* vfunc_03(int a1);
};

BlendFrameController* BlendFrameController::vfunc_03(int a1)
{
    sub_00225E50();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

