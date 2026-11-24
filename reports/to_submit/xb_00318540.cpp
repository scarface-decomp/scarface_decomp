// bin: xb
// va: 0x00318540
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318540 (0x00318540, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FCD0[];
extern "C" char DAT_0042FCE4[];
extern "C" Object DAT_0048B208;
extern "C" char sub_001781E0[];

void __cdecl sub_00318540(void)
{
    DAT_0048B208.sub_0006F880((int)DAT_0042FCE4, (int)DAT_0042FCD0, (int)sub_001781E0, 0, 2, 2);
}
