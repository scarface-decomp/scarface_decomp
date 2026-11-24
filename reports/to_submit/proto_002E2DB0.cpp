// bin: proto
// va: 0x002E2DB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2DB0 (Proto 0x002E2DB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003FDE48[];
extern "C" Object DAT_00453BA4;
extern "C" char sub_00083460[];

void __cdecl sub_002E2DB0(void)
{
    DAT_00453BA4.sub_000654B0(0, (int)DAT_003FDE48, (int)sub_00083460, 0, 2, 3);
}
