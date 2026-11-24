// bin: xb
// va: 0x00317DD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317DD0 (0x00317DD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F444[];
extern "C" Object DAT_0048A978;
extern "C" char sub_001618F0[];

void __cdecl sub_00317DD0(void)
{
    DAT_0048A978.sub_0006F830(0, (int)DAT_0042F444, (int)sub_001618F0, 0, 2, 2);
}
