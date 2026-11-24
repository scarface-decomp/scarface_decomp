// bin: xb
// va: 0x00314AB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314AB0 (0x00314AB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042320C[];
extern "C" Object DAT_00481780;
extern "C" char sub_0008FBE0[];

void __cdecl sub_00314AB0(void)
{
    DAT_00481780.sub_0006F830(0, (int)DAT_0042320C, (int)sub_0008FBE0, 0, 1, 1);
}
