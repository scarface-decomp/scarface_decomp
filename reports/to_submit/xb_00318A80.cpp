// bin: xb
// va: 0x00318A80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318A80 (0x00318A80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004302A0[];
extern "C" char DAT_004302B0[];
extern "C" Object DAT_0048B940;
extern "C" char sub_001786E0[];

void __cdecl sub_00318A80(void)
{
    DAT_0048B940.sub_0006F830((int)DAT_004302B0, (int)DAT_004302A0, (int)sub_001786E0, 0, 4, 4);
}
