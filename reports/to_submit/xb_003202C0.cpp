// bin: xb
// va: 0x003202C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003202C0 (0x003202C0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D32B8[];
extern "C" Object DAT_004928D4;
extern "C" char sub_002317A0[];

void __cdecl sub_003202C0(void)
{
    DAT_004928D4.sub_000EB3A0(47, 41, 18, 73, 6, (int)DAT_003D32B8, (int)sub_002317A0, 1, 0, 1);
}
