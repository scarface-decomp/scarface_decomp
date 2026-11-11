// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/IsCrouchRunCondition.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] IsCrouchRunCondition::vfunc_03 (0x000DDD70, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// IsCrouchRunCondition::vfunc_03 (0x000DDD70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6BFC[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_00021870(void);

class IsCrouchRunCondition
{
public:
    virtual void vfunc_00();
    virtual IsCrouchRunCondition* vfunc_03(int a1);
};

IsCrouchRunCondition* IsCrouchRunCondition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A6BFC;
    sub_00021870();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

