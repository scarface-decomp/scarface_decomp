// bin: xb
// va: 0x00314B30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314B30 (0x00314B30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00423270[];
extern "C" Object DAT_00481830;
extern "C" char sub_00022720[];

void __cdecl sub_00314B30(void)
{
    DAT_00481830.sub_0006F880(0, (int)DAT_00423270, (int)sub_00022720, 0, 2, 2);
}
