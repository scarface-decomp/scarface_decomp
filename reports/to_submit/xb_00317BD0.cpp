// bin: xb
// va: 0x00317BD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317BD0 (0x00317BD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F0FC[];
extern "C" char DAT_0042F110[];
extern "C" Object DAT_0048A73C;
extern "C" char sub_0015D340[];

void __cdecl sub_00317BD0(void)
{
    DAT_0048A73C.sub_0006F830((int)DAT_0042F110, (int)DAT_0042F0FC, (int)sub_0015D340, 0, 7, 7);
}
