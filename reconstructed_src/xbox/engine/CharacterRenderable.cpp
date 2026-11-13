// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CharacterRenderable.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::CharacterRenderable::vfunc_10 (0x00050DA0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// renderer::CharacterRenderable::vfunc_10 (0x00050DA0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000589C0(void);

namespace renderer {

class CharacterRenderable
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
    char m_pad04[0x80];
    int m_Field84; // +0x84
};

void CharacterRenderable::vfunc_10()
{
    int r_eax;

    r_eax = m_Field84;
    if (r_eax) {
        sub_000589C0();
    }
}

}

// ============================================================================
// [VERIFIED] renderer::CharacterRenderable::vfunc_03 (0x000511B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::CharacterRenderable::vfunc_03 (0x000511B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00050FC0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace renderer {

class CharacterRenderable
{
public:
    virtual CharacterRenderable* vfunc_03(int a1);
};

CharacterRenderable* CharacterRenderable::vfunc_03(int a1)
{
    sub_00050FC0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

