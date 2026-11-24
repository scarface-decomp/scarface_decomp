// bin: xb
// va: 0x00316670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316670 (0x00316670, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00427878[];
extern "C" Object DAT_00489224;
extern "C" char sub_000EEB60[];

void __cdecl sub_00316670(void)
{
    DAT_00489224.sub_0006F790(0, (int)DAT_00427878, (int)sub_000EEB60, 0, 2, 2);
}
