// bin: xb
// va: 0x00314DC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314DC0 (0x00314DC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00423C58[];
extern "C" Object DAT_00481C20;
extern "C" char sub_00098C10[];

void __cdecl sub_00314DC0(void)
{
    DAT_00481C20.sub_0006F790(0, (int)DAT_00423C58, (int)sub_00098C10, 0, 2, 2);
}
