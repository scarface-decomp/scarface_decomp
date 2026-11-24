// bin: xb
// va: 0x00318560
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318560 (0x00318560, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FCF4[];
extern "C" char DAT_0042FD08[];
extern "C" Object DAT_0048B234;
extern "C" char sub_00178CA0[];

void __cdecl sub_00318560(void)
{
    DAT_0048B234.sub_0006F830((int)DAT_0042FD08, (int)DAT_0042FCF4, (int)sub_00178CA0, 0, 4, 4);
}
