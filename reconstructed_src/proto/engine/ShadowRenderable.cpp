// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ShadowRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::ShadowRenderable::vfunc_09 (0x0004F8B0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::ShadowRenderable::vfunc_09 (Proto 0x0004F8B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0004EB90(void);

namespace renderer {

class ShadowRenderable
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
    virtual void vfunc_09(int a1);
};

void ShadowRenderable::vfunc_09(int a1)
{
    sub_0004EB90();
}

}

// ============================================================================
// [VERIFIED] renderer::ShadowRenderable::vfunc_10 (0x0004F8C0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Calls sub_0004EF40 when the value at +0x8C is set.
// ============================================================================
// bin: proto
// va: 0x0004F8C0
// what: Calls sub_0004EF40 when the value at +0x8C is set.
// tool: Claude Opus 5.5 (transplanted from xb:0x00050DA0, nearest by portal/tools/similar.py)
// renderer::ShadowRenderable::vfunc_10
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0004EF40(void);


namespace renderer {
class ShadowRenderable
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
    char m_pad04[0x88];
    int m_Field8C; // +0x8C
};

void ShadowRenderable::vfunc_10()
{
    int r_eax;

    r_eax = m_Field8C;
    if (r_eax) {
        sub_0004EF40();
    }
}
}

