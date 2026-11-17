// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISRenderableAnimationAction.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISRenderableAnimationAction::vfunc_03 (0x0015EF90, 88 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISRenderableAnimationAction::vfunc_03 (Proto 0x0015EF90, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00393DC4[];
extern "C" void __cdecl sub_00025160(int);

class NISRenderableAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISRenderableAnimationAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

NISRenderableAnimationAction* NISRenderableAnimationAction::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field14;
    *(int*)this = (int)DAT_00393DC4;
    m_Field10 = 0;
    if (m_Field14) {
        ((Object*)t1)->vfunc_01();
        m_Field14 = 0;
    }
    t3 = m_Field08;
    if (m_Field08) {
        ((Object*)t3)->vfunc_01();
        m_Field08 = 0;
    }
    t5 = m_Field0C;
    if (m_Field0C) {
        *(int*)(t5 + 36) -= 1;
        m_Field0C = 0;
    }
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

