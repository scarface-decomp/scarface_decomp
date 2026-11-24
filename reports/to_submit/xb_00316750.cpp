// bin: xb
// va: 0x00316750
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316750 (0x00316750, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00427920[];
extern "C" Object DAT_00489358;
extern "C" char sub_000EEC10[];

void __cdecl sub_00316750(void)
{
    DAT_00489358.sub_0006F830(0, (int)DAT_00427920, (int)sub_000EEC10, 0, 2, 2);
}
