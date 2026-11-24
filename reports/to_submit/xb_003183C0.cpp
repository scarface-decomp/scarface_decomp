// bin: xb
// va: 0x003183C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003183C0 (0x003183C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FB1C[];
extern "C" char DAT_0042FB2C[];
extern "C" Object DAT_0048AFF8;
extern "C" char sub_00178BB0[];

void __cdecl sub_003183C0(void)
{
    DAT_0048AFF8.sub_0006F880((int)DAT_0042FB2C, (int)DAT_0042FB1C, (int)sub_00178BB0, 0, 4, 11);
}
