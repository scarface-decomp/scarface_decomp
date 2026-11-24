// bin: xb
// va: 0x00316380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316380 (0x00316380, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004276D4[];
extern "C" Object DAT_00487A44;
extern "C" char sub_000EA530[];

void __cdecl sub_00316380(void)
{
    DAT_00487A44.sub_0006F880(0, (int)DAT_004276D4, (int)sub_000EA530, 0, 0, 1);
}
