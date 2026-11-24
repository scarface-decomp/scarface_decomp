// bin: proto
// va: 0x002ECC50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECC50 (Proto 0x002ECC50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427944[];
extern "C" Object DAT_004631BC;
extern "C" char sub_001ECCB0[];

void __cdecl sub_002ECC50(void)
{
    DAT_004631BC.sub_00065550(0, (int)DAT_00427944, (int)sub_001ECCB0, 0, 1, 1);
}
