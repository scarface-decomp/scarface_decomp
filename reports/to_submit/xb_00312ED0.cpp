// bin: xb
// va: 0x00312ED0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312ED0 (0x00312ED0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041C314[];
extern "C" Object DAT_0047497C;
extern "C" char sub_00022720[];

void __cdecl sub_00312ED0(void)
{
    DAT_0047497C.sub_0006F880(0, (int)DAT_0041C314, (int)sub_00022720, 0, 1, 2);
}
