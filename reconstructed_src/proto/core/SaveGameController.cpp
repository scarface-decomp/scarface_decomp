// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/SaveGameController.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SaveGameController::vfunc_00 (0x000B9330, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SaveGameController::vfunc_00 (0x000B9330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003FF558[];

class SaveGameController
{
public:
    virtual void* vfunc_00();
};

void* SaveGameController::vfunc_00()
{
    return DAT_003FF558;
}

// ============================================================================
// [VERIFIED] SaveGameController::vfunc_01 (0x000B9B40, 46 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SaveGameController::vfunc_01 (Proto 0x000B9B40, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6C
{
    void sub_001B7A10();
};

extern "C" char DAT_0038488C[];
extern "C" void __cdecl sub_00025160(int);

class SaveGameController
{
public:
    virtual void vfunc_00();
    virtual SaveGameController* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x68];
    Field6C m_Field6C; // +0x6C
};

SaveGameController* SaveGameController::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0038488C;
    m_Field6C.sub_001B7A10();
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

