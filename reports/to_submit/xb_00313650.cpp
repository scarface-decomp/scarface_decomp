// bin: xb
// va: 0x00313650
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313650 (0x00313650, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DD44[];
extern "C" Object DAT_00475C08;
extern "C" char sub_000607A0[];

void __cdecl sub_00313650(void)
{
    DAT_00475C08.sub_0006F830(0, (int)DAT_0041DD44, (int)sub_000607A0, 0, 2, 3);
}
