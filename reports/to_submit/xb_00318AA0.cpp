// bin: xb
// va: 0x00318AA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318AA0 (0x00318AA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004302C0[];
extern "C" char DAT_004302D0[];
extern "C" Object DAT_0048B96C;
extern "C" char sub_00178710[];

void __cdecl sub_00318AA0(void)
{
    DAT_0048B96C.sub_0006F880((int)DAT_004302D0, (int)DAT_004302C0, (int)sub_00178710, 0, 2, 2);
}
