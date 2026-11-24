// bin: proto
// va: 0x002E27E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E27E0 (Proto 0x002E27E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0038292C[];
extern "C" Object DAT_00453764;
extern "C" char sub_0006E820[];

void __cdecl sub_002E27E0(void)
{
    DAT_00453764.sub_000D8CC0(13, 7, 35, 70, 39, (int)DAT_0038292C, (int)sub_0006E820, 509, 3, 1);
}
