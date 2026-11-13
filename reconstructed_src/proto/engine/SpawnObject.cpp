// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SpawnObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SpawnObject::vfunc_01 (0x001B0DC0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NestSpawnObject::vfunc_01 (0x001E34C0), which was matched first;
// its addresses and names were swapped for this function's.
// SpawnObject::vfunc_01 (0x001B0DC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E6DD0(int);
};

extern "C" char DAT_003A2B6C[];
extern "C" int DAT_00462ED0;
extern "C" void __cdecl sub_00025160(int);

class SpawnObject
{
public:
    virtual void vfunc_00();
    virtual SpawnObject* vfunc_01(int a1);
    void sub_000277E0();
};

SpawnObject* SpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A2B6C;
    ((Object*)DAT_00462ED0)->sub_001E6DD0((int)this);
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

