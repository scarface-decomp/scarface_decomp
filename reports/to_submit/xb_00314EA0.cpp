// bin: xb
// va: 0x00314EA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314EA0 (0x00314EA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423CB8[];
extern "C" Object DAT_00481D64;
extern "C" char sub_00098E00[];

void __cdecl sub_00314EA0(void)
{
    DAT_00481D64.sub_0006F740(0, (int)DAT_00423CB8, (int)sub_00098E00, 0, 3, 3);
}
