// bin: xb
// va: 0x0031B440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B440 (0x0031B440, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00439CB8[];
extern "C" Object DAT_0048EB8C;
extern "C" char sub_001CE0A0[];

void __cdecl sub_0031B440(void)
{
    DAT_0048EB8C.sub_0006F880(0, (int)DAT_00439CB8, (int)sub_001CE0A0, 0, 1, 1);
}
