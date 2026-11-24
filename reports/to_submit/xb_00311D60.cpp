// bin: xb
// va: 0x00311D60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311D60 (0x00311D60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004197F0[];
extern "C" Object DAT_00471174;
extern "C" char sub_00018EA0[];

void __cdecl sub_00311D60(void)
{
    DAT_00471174.sub_0006F830(0, (int)DAT_004197F0, (int)sub_00018EA0, 0, 1, 1);
}
