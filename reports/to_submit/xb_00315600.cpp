// bin: xb
// va: 0x00315600
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315600 (0x00315600, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00424CD4[];
extern "C" Object DAT_00487180;
extern "C" char sub_000CED60[];

void __cdecl sub_00315600(void)
{
    DAT_00487180.sub_0006F880(0, (int)DAT_00424CD4, (int)sub_000CED60, 0, 1, 1);
}
