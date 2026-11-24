// bin: proto
// va: 0x002E6610
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6610 (Proto 0x002E6610, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B618[];
extern "C" char DAT_0040B62C[];
extern "C" Object DAT_0045D6F8;
extern "C" char sub_00158430[];

void __cdecl sub_002E6610(void)
{
    DAT_0045D6F8.sub_000654B0((int)DAT_0040B62C, (int)DAT_0040B618, (int)sub_00158430, 0, 3, 3);
}
