// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ScriptCar.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ScriptCar::vfunc_00 (0x001DFEB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ScriptCar::vfunc_00 (0x001DFEB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004265CC[];

class ScriptCar
{
public:
    virtual void* vfunc_00();
};

void* ScriptCar::vfunc_00()
{
    return DAT_004265CC;
}

// ============================================================================
// [VERIFIED] ScriptCar::vfunc_01 (0x001E00F0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// ScriptCar::vfunc_01 (0x001E00F0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9F2C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D8780(void);

class ScriptCar
{
public:
    virtual void vfunc_00();
    virtual ScriptCar* vfunc_01(int a1);
};

ScriptCar* ScriptCar::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A9F2C;
    sub_001D8780();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

