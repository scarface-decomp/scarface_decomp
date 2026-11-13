// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GameSetObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameSetObject::vfunc_00 (0x000277D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// GameSetObject::vfunc_00 (0x000277D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F68D0[];

class GameSetObject
{
public:
    virtual void* vfunc_00();
};

void* GameSetObject::vfunc_00()
{
    return DAT_003F68D0;
}

// ============================================================================
// [VERIFIED] GameSetObject::vfunc_01 (0x00027800, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameSetObject::vfunc_01 (0x00029FB0), which was matched first;
// its addresses and names were swapped for this function's.
// GameSetObject::vfunc_01 (0x00027800, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037EBF4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029D60(int, int);

class GameSetObject
{
public:
    virtual void vfunc_00();
    virtual GameSetObject* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

GameSetObject* GameSetObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0037EBF4;
    sub_00029D60((int)this, (int)(&m_Field20));
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

