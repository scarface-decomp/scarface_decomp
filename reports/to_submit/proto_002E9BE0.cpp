// bin: proto
// va: 0x002E9BE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9BE0 (Proto 0x002E9BE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00417AFC[];
extern "C" char DAT_00417B08[];
extern "C" Object DAT_00460DF4;
extern "C" char sub_001B4360[];

void __cdecl sub_002E9BE0(void)
{
    DAT_00460DF4.sub_000655A0((int)DAT_00417B08, (int)DAT_00417AFC, (int)sub_001B4360, 0, 2, 2);
}
