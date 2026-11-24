// bin: xb
// va: 0x0031E1C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E1C0 (0x0031E1C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C528[];
extern "C" char DAT_0044C538[];
extern "C" Object DAT_004907BC;
extern "C" char sub_002163B0[];

void __cdecl sub_0031E1C0(void)
{
    DAT_004907BC.sub_0006F830((int)DAT_0044C538, (int)DAT_0044C528, (int)sub_002163B0, 0, 3, 3);
}
