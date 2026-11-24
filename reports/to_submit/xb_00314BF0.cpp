// bin: xb
// va: 0x00314BF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314BF0 (0x00314BF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004232D8[];
extern "C" Object DAT_00481938;
extern "C" char sub_0008FC90[];

void __cdecl sub_00314BF0(void)
{
    DAT_00481938.sub_0006F830(0, (int)DAT_004232D8, (int)sub_0008FC90, 0, 1, 1);
}
