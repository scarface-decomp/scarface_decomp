// bin: xb
// va: 0x003144D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003144D0 (0x003144D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042235C[];
extern "C" Object DAT_00480EA0;
extern "C" char sub_000772B0[];

void __cdecl sub_003144D0(void)
{
    DAT_00480EA0.sub_0006F830(0, (int)DAT_0042235C, (int)sub_000772B0, 0, 2, 2);
}
