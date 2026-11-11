// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CarAIBehavior.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 10 functions matched (20.00%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarAIBehavior::vfunc_00 (0x00126290, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAIBehavior::vfunc_00 (0x00126290, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004091D8[];

class CarAIBehavior
{
public:
    virtual void* vfunc_00();
};

void* CarAIBehavior::vfunc_00()
{
    return DAT_004091D8;
}

// ============================================================================
// [VERIFIED] CarAIBehavior::vfunc_01 (0x001291E0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CarAIBehavior::vfunc_01 (0x001291E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001262A0(void);
extern "C" void __cdecl sub_00025160(int);

class CarAIBehavior
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CarAIBehavior* vfunc_01(int a1);
};

CarAIBehavior* CarAIBehavior::vfunc_01(int a1)
{
    sub_001262A0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

