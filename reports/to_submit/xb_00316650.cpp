// bin: xb
// va: 0x00316650
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316650 (0x00316650, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00427864[];
extern "C" Object DAT_004891F8;
extern "C" char sub_000EEB40[];

void __cdecl sub_00316650(void)
{
    DAT_004891F8.sub_0006F790(0, (int)DAT_00427864, (int)sub_000EEB40, 0, 2, 2);
}
