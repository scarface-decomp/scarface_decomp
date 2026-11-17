// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISCharacterAnimationAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISCharacterAnimationAction::vfunc_04 (0x0015E1C0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISCharacterAnimationAction::vfunc_04 (Proto 0x0015E1C0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISCharacterAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
    char m_pad04[0x1D];
    bool m_Field21; // +0x21
};

bool NISCharacterAnimationAction::vfunc_04()
{
    return m_Field21;
}

// ============================================================================
// [VERIFIED] NISCharacterAnimationAction::vfunc_03 (0x0015F4A0, 95 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISCharacterAnimationAction::vfunc_03 (Proto 0x0015F4A0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00393E8C[];
extern "C" char DAT_00393E94[];
extern "C" void __cdecl sub_00025160(int);

class NISCharacterAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISCharacterAnimationAction* vfunc_03(int a1);
    void sub_0001F600();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

NISCharacterAnimationAction* NISCharacterAnimationAction::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_00393E94;
    m_Field08 = (int)DAT_00393E8C;
    if (m_Field0C) {
        ((Object*)t1)->vfunc_01();
        m_Field0C = 0;
    }
    t3 = m_Field14;
    m_Field10 = 0;
    if (m_Field14) {
        ((Object*)t3)->vfunc_01();
        m_Field14 = 0;
    }
    t5 = m_Field18;
    if (m_Field18) {
        *(int*)(t5 + 36) -= 1;
        m_Field18 = 0;
    }
    sub_0001F600();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

