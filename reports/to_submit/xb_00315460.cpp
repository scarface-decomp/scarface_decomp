// bin: xb
// va: 0x00315460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315460 (0x00315460, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424940[];
extern "C" Object DAT_00487028;
extern "C" char sub_000CA770[];

void __cdecl sub_00315460(void)
{
    DAT_00487028.sub_0006F830(0, (int)DAT_00424940, (int)sub_000CA770, 0, 2, 2);
}
