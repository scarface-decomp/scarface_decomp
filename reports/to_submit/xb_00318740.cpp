// bin: xb
// va: 0x00318740
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318740 (0x00318740, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FF04[];
extern "C" char DAT_0042FF24[];
extern "C" Object DAT_0048B4C8;
extern "C" char sub_00178350[];

void __cdecl sub_00318740(void)
{
    DAT_0048B4C8.sub_0006F830((int)DAT_0042FF24, (int)DAT_0042FF04, (int)sub_00178350, 0, 3, 4);
}
