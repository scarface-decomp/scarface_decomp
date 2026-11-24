// bin: xb
// va: 0x00316510
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316510 (0x00316510, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004277C4[];
extern "C" Object DAT_00489040;
extern "C" char sub_000EE900[];

void __cdecl sub_00316510(void)
{
    DAT_00489040.sub_0006F830(0, (int)DAT_004277C4, (int)sub_000EE900, 0, 3, 4);
}
