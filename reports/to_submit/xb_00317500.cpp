// bin: xb
// va: 0x00317500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317500 (0x00317500, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042DDD0[];
extern "C" Object DAT_0048A124;
extern "C" char sub_00149C20[];

void __cdecl sub_00317500(void)
{
    DAT_0048A124.sub_0006F880(0, (int)DAT_0042DDD0, (int)sub_00149C20, 0, 3, 3);
}
