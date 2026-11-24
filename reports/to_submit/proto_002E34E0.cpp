// bin: proto
// va: 0x002E34E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E34E0 (Proto 0x002E34E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF3FC[];
extern "C" char DAT_003FF408[];
extern "C" Object DAT_004595F8;
extern "C" char sub_000BAC90[];

void __cdecl sub_002E34E0(void)
{
    DAT_004595F8.sub_00065550((int)DAT_003FF408, (int)DAT_003FF3FC, (int)sub_000BAC90, 0, 3, 5);
}
