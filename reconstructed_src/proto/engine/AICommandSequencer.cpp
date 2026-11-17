// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AICommandSequencer.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandSequencer::vfunc_00 (0x00116570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandSequencer::vfunc_00 (0x00116570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00408884[];

class AICommandSequencer
{
public:
    virtual void* vfunc_00();
};

void* AICommandSequencer::vfunc_00()
{
    return DAT_00408884;
}

// ============================================================================
// [VERIFIED] AICommandSequencer::vfunc_01 (0x00117EF0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandSequencer::vfunc_01 (Proto 0x00117EF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F45C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00113870(void);

class AICommandSequencer
{
public:
    virtual void vfunc_00();
    virtual AICommandSequencer* vfunc_01(int a1);
    void sub_00029C00();
    void sub_00116500();
};

AICommandSequencer* AICommandSequencer::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0038F45C;
    sub_00113870();
    sub_00116500();
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

