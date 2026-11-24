// bin: proto
// va: 0x002ECB90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECB90 (Proto 0x002ECB90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004278B4[];
extern "C" Object DAT_004630B4;
extern "C" char sub_001ECC50[];

void __cdecl sub_002ECB90(void)
{
    DAT_004630B4.sub_00065550(0, (int)DAT_004278B4, (int)sub_001ECC50, 0, 2, 2);
}
