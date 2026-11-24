// bin: xb
// va: 0x003198C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003198C0 (0x003198C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435FD0[];
extern "C" char DAT_00435FD8[];
extern "C" Object DAT_0048D218;
extern "C" char sub_001BC970[];

void __cdecl sub_003198C0(void)
{
    DAT_0048D218.sub_0006F830((int)DAT_00435FD8, (int)DAT_00435FD0, (int)sub_001BC970, 0, 3, 3);
}
