// bin: xb
// va: 0x00318AC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318AC0 (0x00318AC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004302E0[];
extern "C" char DAT_004302F4[];
extern "C" Object DAT_0048B998;
extern "C" char sub_00178720[];

void __cdecl sub_00318AC0(void)
{
    DAT_0048B998.sub_0006F830((int)DAT_004302F4, (int)DAT_004302E0, (int)sub_00178720, 0, 4, 4);
}
