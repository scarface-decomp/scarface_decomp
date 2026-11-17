// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/FourWheelerPhysicsTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FourWheelerPhysicsTemplate::vfunc_00 (0x001D08D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FourWheelerPhysicsTemplate::vfunc_00 (0x001D08D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004245B8[];

class FourWheelerPhysicsTemplate
{
public:
    virtual void* vfunc_00();
};

void* FourWheelerPhysicsTemplate::vfunc_00()
{
    return DAT_004245B8;
}

// ============================================================================
// [VERIFIED] FourWheelerPhysicsTemplate::vfunc_01 (0x001D08F0, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FourWheelerPhysicsTemplate::vfunc_01 (Proto 0x001D08F0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FourWheelerPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int FourWheelerPhysicsTemplate::vfunc_01(int a1)
{
    return (int)this + ((((a1 >= 4) - 1) & a1) * 2) + 4;
}

// ============================================================================
// [VERIFIED] FourWheelerPhysicsTemplate::vfunc_01 (0x001D0920, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FourWheelerPhysicsTemplate::vfunc_01 (Proto 0x001D0920, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6BF4[];
extern "C" char DAT_003A6C04[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D6020(void);

class FourWheelerPhysicsTemplate
{
public:
    virtual void vfunc_00();
    virtual FourWheelerPhysicsTemplate* vfunc_01(int a1);
    char m_pad04[0x314];
    int m_Field318; // +0x318
};

FourWheelerPhysicsTemplate* FourWheelerPhysicsTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A6C04;
    m_Field318 = (int)DAT_003A6BF4;
    sub_001D6020();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

