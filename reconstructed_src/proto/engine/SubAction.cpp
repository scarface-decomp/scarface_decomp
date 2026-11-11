// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SubAction.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SubAction::vfunc_03 (0x000CF3A0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// SubAction::vfunc_03 (0x000CF3A0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003866C0[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_001F7E30(void);

class SubAction
{
public:
    virtual void vfunc_00();
    virtual SubAction* vfunc_03(int a1);
};

SubAction* SubAction::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003866C0;
    sub_001F7E30();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

