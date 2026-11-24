// bin: xb
// va: 0x003155C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003155C0 (0x003155C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424CBC[];
extern "C" Object DAT_00487128;
extern "C" char sub_000CEE10[];

void __cdecl sub_003155C0(void)
{
    DAT_00487128.sub_0006F830(0, (int)DAT_00424CBC, (int)sub_000CEE10, 0, 2, 13);
}
