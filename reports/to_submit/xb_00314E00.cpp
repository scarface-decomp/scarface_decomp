// bin: xb
// va: 0x00314E00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314E00 (0x00314E00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423C70[];
extern "C" Object DAT_00481C78;
extern "C" char sub_00098CA0[];

void __cdecl sub_00314E00(void)
{
    DAT_00481C78.sub_0006F740(0, (int)DAT_00423C70, (int)sub_00098CA0, 0, 3, 3);
}
