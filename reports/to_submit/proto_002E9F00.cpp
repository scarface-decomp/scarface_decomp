// bin: proto
// va: 0x002E9F00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9F00 (Proto 0x002E9F00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004181CC[];
extern "C" Object DAT_00461110;
extern "C" char sub_001B4B80[];

void __cdecl sub_002E9F00(void)
{
    DAT_00461110.sub_000654B0(0, (int)DAT_004181CC, (int)sub_001B4B80, 0, 2, 3);
}
