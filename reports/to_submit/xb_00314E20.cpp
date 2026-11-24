// bin: xb
// va: 0x00314E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314E20 (0x00314E20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_00423C88[];
extern "C" Object DAT_00481CB4;
extern "C" char sub_00098D40[];

void __cdecl sub_00314E20(void)
{
    DAT_00481CB4.sub_0006F7E0(0, (int)DAT_00423C88, (int)sub_00098D40, 0, 2, 2);
}
