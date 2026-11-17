// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ActionState.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ActionState::vfunc_01 (0x0015D7E0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// ActionState::vfunc_01 (0x0015D7E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3634[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00029F90(void);

class ActionState
{
public:
    virtual void vfunc_00();
    virtual ActionState* vfunc_01(int a1);
};

ActionState* ActionState::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B3634;
    sub_00029F90();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ActionState::vfunc_04 (0x0017ACB0, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RageState::vfunc_05 (Proto 0x00157290), which was matched first;
// its addresses and names were swapped for this function's.
// ActionState::vfunc_04 (Proto 0x0017ACB0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00026EC0(int);
    void sub_00026EE0();
};

class ActionState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_0002B700(int);
};

void ActionState::vfunc_04(int a1)
{
    int local_4;

    ((Object*)(int)(&local_4))->sub_00026EC0(10);
    sub_0002B700(a1);
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

