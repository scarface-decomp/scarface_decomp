// bin: xb
// va: 0x00318500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318500 (0x00318500, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FC80[];
extern "C" char DAT_0042FC94[];
extern "C" Object DAT_0048B1B0;
extern "C" char sub_001781C0[];

void __cdecl sub_00318500(void)
{
    DAT_0048B1B0.sub_0006F880((int)DAT_0042FC94, (int)DAT_0042FC80, (int)sub_001781C0, 0, 2, 2);
}
