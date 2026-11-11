// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/CollisionBehaviourTypeGroup.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 13 functions matched (23.08%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_00 (0x00012850, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CollisionBehaviourTypeGroup::vfunc_00 (0x00012850, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F41B0[];

class CollisionBehaviourTypeGroup
{
public:
    virtual void* vfunc_00();
};

void* CollisionBehaviourTypeGroup::vfunc_00()
{
    return DAT_003F41B0;
}

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_01 (0x00014470, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// CollisionBehaviourTypeGroup::vfunc_01 (0x00014470, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CDE4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class CollisionBehaviourTypeGroup
{
public:
    virtual void vfunc_00();
    virtual CollisionBehaviourTypeGroup* vfunc_01(int a1);
};

CollisionBehaviourTypeGroup* CollisionBehaviourTypeGroup::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0037CDE4;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CollisionBehaviourTypeGroup::vfunc_11 (0x001B7A10, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_10 (0x002A9290), which was matched first;
// its addresses and names were swapped for this function's.
// CollisionBehaviourTypeGroup::vfunc_11 (0x001B7A10, 1 bytes)
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
    virtual void vfunc_11();
};

void CollisionBehaviourTypeGroup::vfunc_11()
{
}

