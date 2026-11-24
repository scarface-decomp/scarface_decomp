// bin: proto
// va: 0x002E5980
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5980 (Proto 0x002E5980, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00409D34[];
extern "C" char DAT_00409D44[];
extern "C" Object DAT_0045C748;
extern "C" char sub_00141D90[];

void __cdecl sub_002E5980(void)
{
    DAT_0045C748.sub_000654B0((int)DAT_00409D44, (int)DAT_00409D34, (int)sub_00141D90, 0, 3, 3);
}
