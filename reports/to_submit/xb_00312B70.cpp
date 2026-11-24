// bin: xb
// va: 0x00312B70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312B70 (0x00312B70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BC88[];
extern "C" char DAT_0041BC90[];
extern "C" Object DAT_0047432C;
extern "C" char sub_0002DCE0[];

void __cdecl sub_00312B70(void)
{
    DAT_0047432C.sub_0006F830((int)DAT_0041BC90, (int)DAT_0041BC88, (int)sub_0002DCE0, 0, 2, 2);
}
