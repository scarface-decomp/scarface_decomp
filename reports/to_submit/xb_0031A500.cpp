// bin: xb
// va: 0x0031A500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A500 (0x0031A500, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043748C[];
extern "C" char DAT_00437498[];
extern "C" Object DAT_0048DC94;
extern "C" char sub_001BEB20[];

void __cdecl sub_0031A500(void)
{
    DAT_0048DC94.sub_0006F830((int)DAT_00437498, (int)DAT_0043748C, (int)sub_001BEB20, 0, 6, 7);
}
