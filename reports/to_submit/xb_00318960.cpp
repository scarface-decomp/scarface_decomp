// bin: xb
// va: 0x00318960
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318960 (0x00318960, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043015C[];
extern "C" char DAT_00430164[];
extern "C" Object DAT_0048B7B4;
extern "C" char sub_00178570[];

void __cdecl sub_00318960(void)
{
    DAT_0048B7B4.sub_0006F880((int)DAT_00430164, (int)DAT_0043015C, (int)sub_00178570, 0, 2, 2);
}
