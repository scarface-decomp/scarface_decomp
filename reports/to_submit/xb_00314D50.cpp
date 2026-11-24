// bin: xb
// va: 0x00314D50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314D50 (0x00314D50, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A4810[];
extern "C" Object DAT_00481BA0;
extern "C" char sub_00097870[];

void __cdecl sub_00314D50(void)
{
    DAT_00481BA0.sub_000EB3A0(23, 25, 32, 63, 32, (int)DAT_003A4810, (int)sub_00097870, 80, 0, 0);
}
