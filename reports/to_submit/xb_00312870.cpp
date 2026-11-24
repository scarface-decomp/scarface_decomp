// bin: xb
// va: 0x00312870
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312870 (0x00312870, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B5D8[];
extern "C" char DAT_0041B5E0[];
extern "C" Object DAT_004740F0;
extern "C" char sub_0002CE80[];

void __cdecl sub_00312870(void)
{
    DAT_004740F0.sub_0006F830((int)DAT_0041B5E0, (int)DAT_0041B5D8, (int)sub_0002CE80, 0, 3, 10);
}
