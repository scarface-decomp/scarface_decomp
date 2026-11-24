// bin: xb
// va: 0x00313960
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313960 (0x00313960, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041E91C[];
extern "C" Object DAT_00476B10;
extern "C" char sub_00068A60[];

void __cdecl sub_00313960(void)
{
    DAT_00476B10.sub_0006F880(0, (int)DAT_0041E91C, (int)sub_00068A60, 0, 2, 2);
}
