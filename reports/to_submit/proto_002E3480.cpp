// bin: proto
// va: 0x002E3480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3480 (Proto 0x002E3480, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF39C[];
extern "C" char DAT_003FF3A8[];
extern "C" Object DAT_00459574;
extern "C" char sub_000BAC40[];

void __cdecl sub_002E3480(void)
{
    DAT_00459574.sub_00065550((int)DAT_003FF3A8, (int)DAT_003FF39C, (int)sub_000BAC40, 0, 3, 3);
}
