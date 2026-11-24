// bin: proto
// va: 0x002E34A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E34A0 (Proto 0x002E34A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF3BC[];
extern "C" char DAT_003FF3C8[];
extern "C" Object DAT_004595A0;
extern "C" char sub_000BAC60[];

void __cdecl sub_002E34A0(void)
{
    DAT_004595A0.sub_00065550((int)DAT_003FF3C8, (int)DAT_003FF3BC, (int)sub_000BAC60, 0, 3, 3);
}
