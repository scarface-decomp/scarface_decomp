// bin: xb
// va: 0x00317280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317280 (0x00317280, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B0B4[];
extern "C" Object DAT_00489B1C;
extern "C" char sub_0011CED0[];

void __cdecl sub_00317280(void)
{
    DAT_00489B1C.sub_0006F830(0, (int)DAT_0042B0B4, (int)sub_0011CED0, 0, 2, 2);
}
