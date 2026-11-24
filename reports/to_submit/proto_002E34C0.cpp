// bin: proto
// va: 0x002E34C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E34C0 (Proto 0x002E34C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF3DC[];
extern "C" char DAT_003FF3E8[];
extern "C" Object DAT_004595CC;
extern "C" char sub_000BAC80[];

void __cdecl sub_002E34C0(void)
{
    DAT_004595CC.sub_00065550((int)DAT_003FF3E8, (int)DAT_003FF3DC, (int)sub_000BAC80, 0, 2, 2);
}
