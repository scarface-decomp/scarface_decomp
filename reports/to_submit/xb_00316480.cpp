// bin: xb
// va: 0x00316480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316480 (0x00316480, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00427758[];
extern "C" Object DAT_00488FB4;
extern "C" char sub_000EB640[];

void __cdecl sub_00316480(void)
{
    DAT_00488FB4.sub_0006F830(0, (int)DAT_00427758, (int)sub_000EB640, 0, 1, 1);
}
