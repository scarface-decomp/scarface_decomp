// bin: proto
// va: 0x002E1650
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1650 (Proto 0x002E1650, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F8A3C[];
extern "C" Object DAT_0044A63C;
extern "C" char sub_00055C60[];

void __cdecl sub_002E1650(void)
{
    DAT_0044A63C.sub_00065550(0, (int)DAT_003F8A3C, (int)sub_00055C60, 0, 2, 5);
}
