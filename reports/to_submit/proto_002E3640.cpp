// bin: proto
// va: 0x002E3640
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3640 (Proto 0x002E3640, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF668[];
extern "C" Object DAT_004597DC;
extern "C" char sub_000BB180[];

void __cdecl sub_002E3640(void)
{
    DAT_004597DC.sub_00065550(0, (int)DAT_003FF668, (int)sub_000BB180, 0, 1, 1);
}
