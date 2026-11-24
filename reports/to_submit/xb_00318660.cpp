// bin: xb
// va: 0x00318660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318660 (0x00318660, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FE0C[];
extern "C" char DAT_0042FE24[];
extern "C" Object DAT_0048B394;
extern "C" char sub_00178290[];

void __cdecl sub_00318660(void)
{
    DAT_0048B394.sub_0006F790((int)DAT_0042FE24, (int)DAT_0042FE0C, (int)sub_00178290, 0, 2, 2);
}
