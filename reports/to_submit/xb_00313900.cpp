// bin: xb
// va: 0x00313900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313900 (0x00313900, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041E8F0[];
extern "C" Object DAT_00476A8C;
extern "C" char sub_000689D0[];

void __cdecl sub_00313900(void)
{
    DAT_00476A8C.sub_0006F880(0, (int)DAT_0041E8F0, (int)sub_000689D0, 0, 2, 2);
}
