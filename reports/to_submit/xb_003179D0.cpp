// bin: xb
// va: 0x003179D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003179D0 (0x003179D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042E9AC[];
extern "C" char DAT_0042E9BC[];
extern "C" Object DAT_0048A4D4;
extern "C" char sub_0015CF20[];

void __cdecl sub_003179D0(void)
{
    DAT_0048A4D4.sub_0006F790((int)DAT_0042E9BC, (int)DAT_0042E9AC, (int)sub_0015CF20, 0, 3, 3);
}
