// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CarAIBehavior.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 10 functions matched (30.00%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CarAIBehavior::vfunc_32 (0x0013CE80, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAIBehavior::vfunc_32 (0x0013CE80, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00104E10(void);

class CarAIBehavior
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_32();
};

void CarAIBehavior::vfunc_32()
{
    sub_00104E10();
}

// ============================================================================
// [VERIFIED] CarAIBehavior::vfunc_00 (0x00141C00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CarAIBehavior::vfunc_00 (0x00141C00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042DF3C[];

class CarAIBehavior
{
public:
    virtual void* vfunc_00();
};

void* CarAIBehavior::vfunc_00()
{
    return DAT_0042DF3C;
}

// ============================================================================
// [VERIFIED] CarAIBehavior::vfunc_01 (0x00144D20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// CarAIBehavior::vfunc_01 (0x00144D20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00141C10(void);
extern "C" void __cdecl sub_00027600(int);

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
    sub_00141C10();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

