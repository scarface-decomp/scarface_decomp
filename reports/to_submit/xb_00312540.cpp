// bin: xb
// va: 0x00312540
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312540 (0x00312540, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041A984[];
extern "C" Object DAT_004717F4;
extern "C" char sub_00024AB0[];

void __cdecl sub_00312540(void)
{
    DAT_004717F4.sub_0006F830(0, (int)DAT_0041A984, (int)sub_00024AB0, 0, 2, 2);
}
