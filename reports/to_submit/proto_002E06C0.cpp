// bin: proto
// va: 0x002E06C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E06C0 (Proto 0x002E06C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F59B8[];
extern "C" Object DAT_00446BCC;
extern "C" char sub_00022C90[];

void __cdecl sub_002E06C0(void)
{
    DAT_00446BCC.sub_00065550(0, (int)DAT_003F59B8, (int)sub_00022C90, 0, 3, 3);
}
