// bin: xb
// va: 0x00315360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315360 (0x00315360, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424744[];
extern "C" char DAT_0042475C[];
extern "C" Object DAT_00486EC8;
extern "C" char sub_000C9FE0[];

void __cdecl sub_00315360(void)
{
    DAT_00486EC8.sub_0006F830((int)DAT_0042475C, (int)DAT_00424744, (int)sub_000C9FE0, 0, 3, 3);
}
