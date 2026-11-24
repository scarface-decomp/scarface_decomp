// bin: xb
// va: 0x00316360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316360 (0x00316360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004276C4[];
extern "C" Object DAT_00487A18;
extern "C" char sub_000EA4D0[];

void __cdecl sub_00316360(void)
{
    DAT_00487A18.sub_0006F830(0, (int)DAT_004276C4, (int)sub_000EA4D0, 0, 2, 3);
}
