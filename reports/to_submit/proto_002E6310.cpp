// bin: proto
// va: 0x002E6310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6310 (Proto 0x002E6310, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B2D4[];
extern "C" char DAT_0040B2E8[];
extern "C" Object DAT_0045D2D8;
extern "C" char sub_001581F0[];

void __cdecl sub_002E6310(void)
{
    DAT_0045D2D8.sub_000654B0((int)DAT_0040B2E8, (int)DAT_0040B2D4, (int)sub_001581F0, 0, 3, 4);
}
