// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GameDatabase.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameDatabase::vfunc_00 (0x000EDA60, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameDatabase::vfunc_00 (0x000EDA60, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EC260();
};

extern "C" char DAT_003A93E0[];
extern "C" void __cdecl sub_00027600(int);

class GameDatabase
{
public:
    virtual GameDatabase* vfunc_00(int a1);
    char m_pad04[0x608];
    int m_Field60C; // +0x60C
};

GameDatabase* GameDatabase::vfunc_00(int a1)
{
    int r_edi, r_esi;

    *(int*)this = (int)DAT_003A93E0;
    r_esi = (int)(&m_Field60C);
    r_edi = 193;
    do {
        r_esi -= 8;
        ((Object*)r_esi)->sub_000EC260();
        r_edi -= 1;
    } while (r_edi);
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

