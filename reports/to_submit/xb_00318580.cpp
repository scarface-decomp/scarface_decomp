// bin: xb
// va: 0x00318580
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318580 (0x00318580, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FD18[];
extern "C" char DAT_0042FD28[];
extern "C" Object DAT_0048B260;
extern "C" char sub_001781F0[];

void __cdecl sub_00318580(void)
{
    DAT_0048B260.sub_0006F830((int)DAT_0042FD28, (int)DAT_0042FD18, (int)sub_001781F0, 0, 2, 2);
}
