// bin: xb
// va: 0x00314A30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314A30 (0x00314A30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004231C0[];
extern "C" Object DAT_004816D0;
extern "C" char sub_0008FB50[];

void __cdecl sub_00314A30(void)
{
    DAT_004816D0.sub_0006F790(0, (int)DAT_004231C0, (int)sub_0008FB50, 0, 1, 1);
}
