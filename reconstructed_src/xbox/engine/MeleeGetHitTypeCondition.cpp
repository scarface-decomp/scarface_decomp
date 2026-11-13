// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MeleeGetHitTypeCondition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MeleeGetHitTypeCondition::vfunc_08 (0x000DD240, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as UpperBodyAnimStateCondition::vfunc_08 (0x000DD100), which was matched first;
// its addresses and names were swapped for this function's.
// MeleeGetHitTypeCondition::vfunc_08 (0x000DD240, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004250C0[];

class MeleeGetHitTypeCondition
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
    virtual int vfunc_08(int a1);
};

int MeleeGetHitTypeCondition::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)1) goto L_16;
        r_eax = DAT_004250C0[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] MeleeGetHitTypeCondition::vfunc_03 (0x000DD8C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// MeleeGetHitTypeCondition::vfunc_03 (0x000DD8C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6854[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00021870(void);

class MeleeGetHitTypeCondition
{
public:
    virtual void vfunc_00();
    virtual MeleeGetHitTypeCondition* vfunc_03(int a1);
};

MeleeGetHitTypeCondition* MeleeGetHitTypeCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A6854;
    sub_00021870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

