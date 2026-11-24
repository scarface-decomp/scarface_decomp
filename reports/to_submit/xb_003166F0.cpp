// bin: xb
// va: 0x003166F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003166F0 (0x003166F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004278D8[];
extern "C" Object DAT_004892D4;
extern "C" char sub_000EEBD0[];

void __cdecl sub_003166F0(void)
{
    DAT_004892D4.sub_0006F790(0, (int)DAT_004278D8, (int)sub_000EEBD0, 0, 1, 1);
}
