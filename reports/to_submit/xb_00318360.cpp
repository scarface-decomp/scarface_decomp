// bin: xb
// va: 0x00318360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318360 (0x00318360, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FAA8[];
extern "C" char DAT_0042FAC0[];
extern "C" Object DAT_0048AF74;
extern "C" char sub_00178060[];

void __cdecl sub_00318360(void)
{
    DAT_0048AF74.sub_0006F880((int)DAT_0042FAC0, (int)DAT_0042FAA8, (int)sub_00178060, 0, 2, 2);
}
