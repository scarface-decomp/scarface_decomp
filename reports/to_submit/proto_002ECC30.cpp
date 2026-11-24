// bin: proto
// va: 0x002ECC30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECC30 (Proto 0x002ECC30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0042792C[];
extern "C" Object DAT_00463190;
extern "C" char sub_001ED3B0[];

void __cdecl sub_002ECC30(void)
{
    DAT_00463190.sub_00065550(0, (int)DAT_0042792C, (int)sub_001ED3B0, 0, 1, 1);
}
