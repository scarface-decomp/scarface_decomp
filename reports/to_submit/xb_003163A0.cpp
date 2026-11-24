// bin: xb
// va: 0x003163A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003163A0 (0x003163A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004276E8[];
extern "C" Object DAT_00488E80;
extern "C" char sub_000EB580[];

void __cdecl sub_003163A0(void)
{
    DAT_00488E80.sub_0006F830(0, (int)DAT_004276E8, (int)sub_000EB580, 0, 1, 1);
}
