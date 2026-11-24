// bin: xb
// va: 0x00313210
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313210 (0x00313210, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041C6BC[];
extern "C" Object DAT_00474DBC;
extern "C" char sub_0003D9D0[];

void __cdecl sub_00313210(void)
{
    DAT_00474DBC.sub_0006F880(0, (int)DAT_0041C6BC, (int)sub_0003D9D0, 0, 1, 1);
}
