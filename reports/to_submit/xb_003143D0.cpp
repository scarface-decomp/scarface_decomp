// bin: xb
// va: 0x003143D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003143D0 (0x003143D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004222A0[];
extern "C" Object DAT_00480D40;
extern "C" char sub_00077230[];

void __cdecl sub_003143D0(void)
{
    DAT_00480D40.sub_0006F790(0, (int)DAT_004222A0, (int)sub_00077230, 0, 1, 1);
}
