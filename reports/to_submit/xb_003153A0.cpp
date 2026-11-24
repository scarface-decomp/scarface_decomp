// bin: xb
// va: 0x003153A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003153A0 (0x003153A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042479C[];
extern "C" char DAT_004247A8[];
extern "C" Object DAT_00486F20;
extern "C" char sub_000CA030[];

void __cdecl sub_003153A0(void)
{
    DAT_00486F20.sub_0006F880((int)DAT_004247A8, (int)DAT_0042479C, (int)sub_000CA030, 0, 3, 3);
}
