// bin: xb
// va: 0x003167F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003167F0 (0x003167F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004279A0[];
extern "C" Object DAT_00489434;
extern "C" char sub_000EEC80[];

void __cdecl sub_003167F0(void)
{
    DAT_00489434.sub_0006F830(0, (int)DAT_004279A0, (int)sub_000EEC80, 0, 2, 2);
}
