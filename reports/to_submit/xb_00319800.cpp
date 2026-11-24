// bin: xb
// va: 0x00319800
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319800 (0x00319800, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435EE4[];
extern "C" char DAT_00435EFC[];
extern "C" Object DAT_0048D13C;
extern "C" char sub_001BC810[];

void __cdecl sub_00319800(void)
{
    DAT_0048D13C.sub_0006F830((int)DAT_00435EFC, (int)DAT_00435EE4, (int)sub_001BC810, 0, 2, 2);
}
