// bin: xb
// va: 0x003179B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003179B0 (0x003179B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042E984[];
extern "C" char DAT_0042E994[];
extern "C" Object DAT_0048A4A8;
extern "C" char sub_0015CEE0[];

void __cdecl sub_003179B0(void)
{
    DAT_0048A4A8.sub_0006F790((int)DAT_0042E994, (int)DAT_0042E984, (int)sub_0015CEE0, 0, 3, 3);
}
