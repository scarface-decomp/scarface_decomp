// bin: xb
// va: 0x00314EC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314EC0 (0x00314EC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00423CC4[];
extern "C" Object DAT_00481D90;
extern "C" char sub_00098F20[];

void __cdecl sub_00314EC0(void)
{
    DAT_00481D90.sub_0006F880(0, (int)DAT_00423CC4, (int)sub_00098F20, 0, 3, 3);
}
