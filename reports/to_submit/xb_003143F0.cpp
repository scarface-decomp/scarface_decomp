// bin: xb
// va: 0x003143F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003143F0 (0x003143F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004222C0[];
extern "C" Object DAT_00480D6C;
extern "C" char sub_00077240[];

void __cdecl sub_003143F0(void)
{
    DAT_00480D6C.sub_0006F790(0, (int)DAT_004222C0, (int)sub_00077240, 0, 1, 1);
}
