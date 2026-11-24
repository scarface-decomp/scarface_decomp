// bin: proto
// va: 0x002E6730
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6730 (Proto 0x002E6730, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B770[];
extern "C" char DAT_0040B77C[];
extern "C" Object DAT_0045D884;
extern "C" char sub_00158530[];

void __cdecl sub_002E6730(void)
{
    DAT_0045D884.sub_000654B0((int)DAT_0040B77C, (int)DAT_0040B770, (int)sub_00158530, 0, 2, 2);
}
