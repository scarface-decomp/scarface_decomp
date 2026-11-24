// bin: xb
// va: 0x00315480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315480 (0x00315480, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00424968[];
extern "C" Object DAT_00487054;
extern "C" char sub_000CA790[];

void __cdecl sub_00315480(void)
{
    DAT_00487054.sub_0006F880(0, (int)DAT_00424968, (int)sub_000CA790, 0, 1, 1);
}
