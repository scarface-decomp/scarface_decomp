// bin: xb
// va: 0x003166D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003166D0 (0x003166D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004278C0[];
extern "C" Object DAT_004892A8;
extern "C" char sub_000EEBC0[];

void __cdecl sub_003166D0(void)
{
    DAT_004892A8.sub_0006F790(0, (int)DAT_004278C0, (int)sub_000EEBC0, 0, 1, 1);
}
