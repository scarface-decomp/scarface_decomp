// bin: xb
// va: 0x00314A70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314A70 (0x00314A70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004231E8[];
extern "C" Object DAT_00481728;
extern "C" char sub_0008FBC0[];

void __cdecl sub_00314A70(void)
{
    DAT_00481728.sub_0006F830(0, (int)DAT_004231E8, (int)sub_0008FBC0, 0, 2, 2);
}
