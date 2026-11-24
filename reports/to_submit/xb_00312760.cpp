// bin: xb
// va: 0x00312760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312760 (0x00312760, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B034[];
extern "C" char DAT_0041B03C[];
extern "C" Object DAT_00471AB8;
extern "C" char sub_00026820[];

void __cdecl sub_00312760(void)
{
    DAT_00471AB8.sub_0006F830((int)DAT_0041B03C, (int)DAT_0041B034, (int)sub_00026820, 0, 3, 3);
}
