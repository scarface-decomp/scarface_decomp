// bin: xb
// va: 0x0031AA40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AA40 (0x0031AA40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437B84[];
extern "C" char DAT_00437B98[];
extern "C" Object DAT_0048E298;
extern "C" char sub_001BF5E0[];

void __cdecl sub_0031AA40(void)
{
    DAT_0048E298.sub_0006F830((int)DAT_00437B98, (int)DAT_00437B84, (int)sub_001BF5E0, 0, 3, 3);
}
