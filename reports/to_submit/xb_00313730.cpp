// bin: xb
// va: 0x00313730
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313730 (0x00313730, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DDCC[];
extern "C" Object DAT_00475D3C;
extern "C" char sub_00060870[];

void __cdecl sub_00313730(void)
{
    DAT_00475D3C.sub_0006F830(0, (int)DAT_0041DDCC, (int)sub_00060870, 0, 2, 2);
}
