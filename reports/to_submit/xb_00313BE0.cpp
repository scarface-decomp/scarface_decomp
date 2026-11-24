// bin: xb
// va: 0x00313BE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313BE0 (0x00313BE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041EEAC[];
extern "C" Object DAT_0047AB00;
extern "C" char sub_00070E40[];

void __cdecl sub_00313BE0(void)
{
    DAT_0047AB00.sub_0006F830(0, (int)DAT_0041EEAC, (int)sub_00070E40, 0, 2, 2);
}
