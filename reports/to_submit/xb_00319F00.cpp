// bin: xb
// va: 0x00319F00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319F00 (0x00319F00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004369B4[];
extern "C" Object DAT_0048D798;
extern "C" char sub_001BD660[];

void __cdecl sub_00319F00(void)
{
    DAT_0048D798.sub_0006F880(0, (int)DAT_004369B4, (int)sub_001BD660, 0, 1, 1);
}
