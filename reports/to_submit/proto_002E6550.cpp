// bin: proto
// va: 0x002E6550
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6550 (Proto 0x002E6550, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B544[];
extern "C" char DAT_0040B554[];
extern "C" Object DAT_0045D5F0;
extern "C" char sub_00158D20[];

void __cdecl sub_002E6550(void)
{
    DAT_0045D5F0.sub_000655A0((int)DAT_0040B554, (int)DAT_0040B544, (int)sub_00158D20, 0, 2, 2);
}
