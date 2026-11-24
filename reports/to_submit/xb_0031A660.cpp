// bin: xb
// va: 0x0031A660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A660 (0x0031A660, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437658[];
extern "C" char DAT_00437668[];
extern "C" Object DAT_0048DE4C;
extern "C" char sub_001BED70[];

void __cdecl sub_0031A660(void)
{
    DAT_0048DE4C.sub_0006F830((int)DAT_00437668, (int)DAT_00437658, (int)sub_001BED70, 0, 3, 3);
}
