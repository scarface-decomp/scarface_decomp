// bin: xb
// va: 0x003198E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003198E0 (0x003198E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435FE8[];
extern "C" char DAT_00435FF0[];
extern "C" Object DAT_0048D244;
extern "C" char sub_001BC990[];

void __cdecl sub_003198E0(void)
{
    DAT_0048D244.sub_0006F830((int)DAT_00435FF0, (int)DAT_00435FE8, (int)sub_001BC990, 0, 3, 3);
}
