// bin: xb
// va: 0x00318460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318460 (0x00318460, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FBD0[];
extern "C" char DAT_0042FBDC[];
extern "C" Object DAT_0048B0D4;
extern "C" char sub_00178140[];

void __cdecl sub_00318460(void)
{
    DAT_0048B0D4.sub_0006F830((int)DAT_0042FBDC, (int)DAT_0042FBD0, (int)sub_00178140, 0, 3, 3);
}
