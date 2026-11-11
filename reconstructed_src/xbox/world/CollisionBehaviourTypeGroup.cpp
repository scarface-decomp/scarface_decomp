// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/CollisionBehaviourTypeGroup.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 14 functions matched (21.43%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004191A0[];

class CollisionBehaviourTypeGroup
{
public:
    virtual void* vfunc_00();
};

void* CollisionBehaviourTypeGroup::vfunc_00()
{
    return DAT_004191A0;
}

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_01 (0x00013840, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CollisionBehaviourTypeGroup::vfunc_01 (0x00013840, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D5DC[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0002C720(void);

class CollisionBehaviourTypeGroup
{
public:
    virtual void vfunc_00();
    virtual CollisionBehaviourTypeGroup* vfunc_01(int a1);
};

CollisionBehaviourTypeGroup* CollisionBehaviourTypeGroup::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039D5DC;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_10 (0x002A9290, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CollisionBehaviourTypeGroup::vfunc_10 (0x002A9290, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class CollisionBehaviourTypeGroup
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
};

void CollisionBehaviourTypeGroup::vfunc_10()
{
}

