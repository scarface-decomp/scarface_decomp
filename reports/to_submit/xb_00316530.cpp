// bin: xb
// va: 0x00316530
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316530 (0x00316530, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_004277D0[];
extern "C" Object DAT_0048906C;
extern "C" char sub_000EE960[];

void __cdecl sub_00316530(void)
{
    DAT_0048906C.sub_0006F7E0(0, (int)DAT_004277D0, (int)sub_000EE960, 0, 2, 3);
}
