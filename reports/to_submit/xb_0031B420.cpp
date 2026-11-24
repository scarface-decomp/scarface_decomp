// bin: xb
// va: 0x0031B420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B420 (0x0031B420, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439C9C[];
extern "C" char DAT_00439CA8[];
extern "C" Object DAT_0048EB60;
extern "C" char sub_001CE090[];

void __cdecl sub_0031B420(void)
{
    DAT_0048EB60.sub_0006F830((int)DAT_00439CA8, (int)DAT_00439C9C, (int)sub_001CE090, 0, 2, 2);
}
