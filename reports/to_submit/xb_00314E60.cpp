// bin: xb
// va: 0x00314E60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314E60 (0x00314E60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423CA0[];
extern "C" Object DAT_00481D0C;
extern "C" char sub_00098D80[];

void __cdecl sub_00314E60(void)
{
    DAT_00481D0C.sub_0006F740(0, (int)DAT_00423CA0, (int)sub_00098D80, 0, 3, 3);
}
