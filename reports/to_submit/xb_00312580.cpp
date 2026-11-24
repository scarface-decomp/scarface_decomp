// bin: xb
// va: 0x00312580
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312580 (0x00312580, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041A9B8[];
extern "C" Object DAT_0047184C;
extern "C" char sub_00024AF0[];

void __cdecl sub_00312580(void)
{
    DAT_0047184C.sub_0006F830(0, (int)DAT_0041A9B8, (int)sub_00024AF0, 0, 3, 3);
}
