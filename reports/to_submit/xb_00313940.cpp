// bin: xb
// va: 0x00313940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313940 (0x00313940, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041E90C[];
extern "C" Object DAT_00476AE4;
extern "C" char sub_00068A30[];

void __cdecl sub_00313940(void)
{
    DAT_00476AE4.sub_0006F880(0, (int)DAT_0041E90C, (int)sub_00068A30, 0, 2, 2);
}
