// bin: xb
// va: 0x00312220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312220 (0x00312220, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419FB0[];
extern "C" char DAT_00419FB8[];
extern "C" Object DAT_00471600;
extern "C" char sub_000209E0[];

void __cdecl sub_00312220(void)
{
    DAT_00471600.sub_0006F830((int)DAT_00419FB8, (int)DAT_00419FB0, (int)sub_000209E0, 0, 2, 2);
}
