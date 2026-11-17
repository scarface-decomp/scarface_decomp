// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GameDatabase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameDatabase::vfunc_00 (0x000DAB90, 59 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameDatabase::vfunc_00 (Proto 0x000DAB90, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D9B50();
};

extern "C" char DAT_003882E4[];
extern "C" void __cdecl sub_00025160(int);

class GameDatabase
{
public:
    virtual GameDatabase* vfunc_00(int a1);
    char m_pad04[0x3D0];
    int m_Field3D4; // +0x3D4
};

GameDatabase* GameDatabase::vfunc_00(int a1)
{
    int r_edi, r_esi;

    *(int*)this = (int)DAT_003882E4;
    r_esi = (int)(&m_Field3D4);
    r_edi = 122;
    do {
        r_esi -= 8;
        ((Object*)r_esi)->sub_000D9B50();
        r_edi -= 1;
    } while (r_edi);
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

