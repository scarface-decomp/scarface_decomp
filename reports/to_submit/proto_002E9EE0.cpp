// bin: proto
// va: 0x002E9EE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9EE0 (Proto 0x002E9EE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004181A4[];
extern "C" char DAT_004181B4[];
extern "C" Object DAT_004610E4;
extern "C" char sub_001B4B60[];

void __cdecl sub_002E9EE0(void)
{
    DAT_004610E4.sub_000654B0((int)DAT_004181B4, (int)DAT_004181A4, (int)sub_001B4B60, 0, 2, 2);
}
