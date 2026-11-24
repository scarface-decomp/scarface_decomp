// bin: xb
// va: 0x00318700
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318700 (0x00318700, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FEC0[];
extern "C" char DAT_0042FED0[];
extern "C" Object DAT_0048B470;
extern "C" char sub_00178E10[];

void __cdecl sub_00318700(void)
{
    DAT_0048B470.sub_0006F830((int)DAT_0042FED0, (int)DAT_0042FEC0, (int)sub_00178E10, 0, 3, 3);
}
