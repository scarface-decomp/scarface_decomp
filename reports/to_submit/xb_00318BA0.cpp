// bin: xb
// va: 0x00318BA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318BA0 (0x00318BA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004303DC[];
extern "C" char DAT_004303F4[];
extern "C" Object DAT_0048BACC;
extern "C" char sub_001787F0[];

void __cdecl sub_00318BA0(void)
{
    DAT_0048BACC.sub_0006F830((int)DAT_004303F4, (int)DAT_004303DC, (int)sub_001787F0, 0, 3, 3);
}
