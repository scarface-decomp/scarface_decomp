// bin: proto
// va: 0x002E2560
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2560 (Proto 0x002E2560, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003FCFC4[];
extern "C" Object DAT_004533AC;
extern "C" char sub_0006C750[];

void __cdecl sub_002E2560(void)
{
    DAT_004533AC.sub_000654B0(0, (int)DAT_003FCFC4, (int)sub_0006C750, 0, 2, 2);
}
