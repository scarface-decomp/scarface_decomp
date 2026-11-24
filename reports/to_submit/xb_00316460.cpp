// bin: xb
// va: 0x00316460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316460 (0x00316460, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00427744[];
extern "C" Object DAT_00488F88;
extern "C" char sub_000EB620[];

void __cdecl sub_00316460(void)
{
    DAT_00488F88.sub_0006F830(0, (int)DAT_00427744, (int)sub_000EB620, 0, 1, 1);
}
