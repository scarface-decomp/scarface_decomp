// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/BlendFrameController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 19 functions matched (10.53%). NOT COMPLETE YET.
// The 17 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::BlendFrameController::vfunc_15 (0x00273720, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the float at the start of the last active blend entry when the entry count at +0x1C is positive, or the default float at DAT_0039D584.
// ============================================================================
// bin: xb
// va: 0x00273720
// what: Returns the float at the start of the last active blend entry when the entry count at +0x1C is positive, or the default float at DAT_0039D584.
// tool: Gemini 4 Neon

extern "C" const float DAT_0039D584;

namespace pure3d {

struct BlendEntry_00273720
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
    BlendEntry_00273720 m_Entries[4]; // +0x20
};

float BlendFrameController::vfunc_15()
{
    if (m_Count > 0)
        return m_Entries[m_Count - 1].m_Field00;
    return DAT_0039D584;
}

}

// ============================================================================
// [VERIFIED] pure3d::BlendFrameController::vfunc_03 (0x00274870, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::BlendFrameController's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class BlendFrameController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BlendFrameController* vfunc_03(unsigned int flags);
    void sub_00274170();
};

#pragma optimize("y", off)
BlendFrameController* BlendFrameController::vfunc_03(unsigned int flags)
{
    sub_00274170();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

