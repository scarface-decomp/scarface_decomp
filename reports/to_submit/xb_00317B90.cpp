// bin: xb
// va: 0x00317B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317B90 (0x00317B90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F0C4[];
extern "C" char DAT_0042F0D0[];
extern "C" Object DAT_0048A6E4;
extern "C" char sub_0015D2E0[];

void __cdecl sub_00317B90(void)
{
    DAT_0048A6E4.sub_0006F830((int)DAT_0042F0D0, (int)DAT_0042F0C4, (int)sub_0015D2E0, 0, 4, 4);
}
