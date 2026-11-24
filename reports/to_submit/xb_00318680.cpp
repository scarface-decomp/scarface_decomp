// bin: xb
// va: 0x00318680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318680 (0x00318680, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FE34[];
extern "C" char DAT_0042FE4C[];
extern "C" Object DAT_0048B3C0;
extern "C" char sub_001782A0[];

void __cdecl sub_00318680(void)
{
    DAT_0048B3C0.sub_0006F790((int)DAT_0042FE4C, (int)DAT_0042FE34, (int)sub_001782A0, 0, 2, 2);
}
