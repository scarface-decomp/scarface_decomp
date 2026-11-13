// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISCharacterEffectAction.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISCharacterEffectAction::vfunc_03 (0x0017F450, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NISCharacterDamageAction::vfunc_03 (0x0017F0B0), which was matched first;
// its addresses and names were swapped for this function's.
// NISCharacterEffectAction::vfunc_03 (0x0017F450, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_003B5FA4[];
extern "C" void __cdecl sub_00027600(int);

class NISCharacterEffectAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISCharacterEffectAction* vfunc_03(int a1);
    void sub_000217F0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

NISCharacterEffectAction* NISCharacterEffectAction::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003B5FA4;
    if (m_Field08) {
        ((Object*)t1)->vfunc_01();
        m_Field08 = 0;
    }
    sub_000217F0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] NISCharacterEffectAction::vfunc_07 (0x001811B0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_04 (0x0002B700), which was matched first;
// its addresses and names were swapped for this function's.
// NISCharacterEffectAction::vfunc_07 (0x001811B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0017F490(void);

class NISCharacterEffectAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_07(int a1);
};

void NISCharacterEffectAction::vfunc_07(int a1)
{
    sub_0017F490();
}

