// bin: xb
// va: 0x00318C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318C60 (0x00318C60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004304C8[];
extern "C" char DAT_004304E4[];
extern "C" Object DAT_0048BBD4;
extern "C" char sub_00178870[];

void __cdecl sub_00318C60(void)
{
    DAT_0048BBD4.sub_0006F830((int)DAT_004304E4, (int)DAT_004304C8, (int)sub_00178870, 0, 2, 3);
}
