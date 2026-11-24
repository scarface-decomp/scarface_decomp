// bin: xb
// va: 0x00318420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318420 (0x00318420, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FB90[];
extern "C" char DAT_0042FB9C[];
extern "C" Object DAT_0048B07C;
extern "C" char sub_001780B0[];

void __cdecl sub_00318420(void)
{
    DAT_0048B07C.sub_0006F880((int)DAT_0042FB9C, (int)DAT_0042FB90, (int)sub_001780B0, 0, 3, 3);
}
