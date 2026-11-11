// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/LookTutorialHUD.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 7 functions matched (28.57%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_00 (0x00185AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_00 (0x00185AB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041062C[];

class LookTutorialHUD
{
public:
    virtual void* vfunc_00();
};

void* LookTutorialHUD::vfunc_00()
{
    return DAT_0041062C;
}

// ============================================================================
// [VERIFIED] LookTutorialHUD::vfunc_01 (0x00186620, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// LookTutorialHUD::vfunc_01 (0x00186620, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C12C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0016E130(void);

class LookTutorialHUD
{
public:
    virtual void vfunc_00();
    virtual LookTutorialHUD* vfunc_01(int a1);
};

LookTutorialHUD* LookTutorialHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039C12C;
    sub_0016E130();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

