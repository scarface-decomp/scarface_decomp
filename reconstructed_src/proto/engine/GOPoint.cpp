// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GOPoint.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GOPoint::vfunc_00 (0x00180170, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GOPoint::vfunc_00 (0x00180170, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004116D8[];

class GOPoint
{
public:
    virtual void* vfunc_00();
};

void* GOPoint::vfunc_00()
{
    return DAT_004116D8;
}

// ============================================================================
// [VERIFIED] GOPoint::vfunc_01 (0x00180BD0, 47 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GOPoint::vfunc_01 (Proto 0x00180BD0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039B09C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00180860(int);

class GOPoint
{
public:
    virtual void vfunc_00();
    virtual GOPoint* vfunc_01(int a1);
    void sub_000277E0();
};

GOPoint* GOPoint::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039B09C;
    sub_00180860((int)this);
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

