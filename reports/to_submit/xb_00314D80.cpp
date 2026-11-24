// bin: xb
// va: 0x00314D80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314D80 (0x00314D80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_00423C48[];
extern "C" Object DAT_00481BC8;
extern "C" char sub_00098BE0[];

void __cdecl sub_00314D80(void)
{
    DAT_00481BC8.sub_0006F7E0(0, (int)DAT_00423C48, (int)sub_00098BE0, 0, 1, 1);
}
