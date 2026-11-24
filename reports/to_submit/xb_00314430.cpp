// bin: xb
// va: 0x00314430
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314430 (0x00314430, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004222F0[];
extern "C" Object DAT_00480DC4;
extern "C" char sub_000774E0[];

void __cdecl sub_00314430(void)
{
    DAT_00480DC4.sub_0006F880(0, (int)DAT_004222F0, (int)sub_000774E0, 0, 3, 3);
}
