// bin: proto
// va: 0x002E3760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3760 (Proto 0x002E3760, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF934[];
extern "C" Object DAT_004598DC;
extern "C" char sub_000BE700[];

void __cdecl sub_002E3760(void)
{
    DAT_004598DC.sub_00065550(0, (int)DAT_003FF934, (int)sub_000BE700, 0, 2, 2);
}
