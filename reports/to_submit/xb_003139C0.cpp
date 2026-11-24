// bin: xb
// va: 0x003139C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003139C0 (0x003139C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041E940[];
extern "C" Object DAT_00476B94;
extern "C" char sub_00068AF0[];

void __cdecl sub_003139C0(void)
{
    DAT_00476B94.sub_0006F740(0, (int)DAT_0041E940, (int)sub_00068AF0, 0, 1, 1);
}
