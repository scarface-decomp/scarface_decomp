// bin: xb
// va: 0x00317A90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317A90 (0x00317A90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042EFE0[];
extern "C" char DAT_0042EFE8[];
extern "C" Object DAT_0048A584;
extern "C" char sub_0015D0C0[];

void __cdecl sub_00317A90(void)
{
    DAT_0048A584.sub_0006F830((int)DAT_0042EFE8, (int)DAT_0042EFE0, (int)sub_0015D0C0, 0, 2, 2);
}
