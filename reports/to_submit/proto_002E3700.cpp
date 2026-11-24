// bin: proto
// va: 0x002E3700
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3700 (Proto 0x002E3700, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF908[];
extern "C" Object DAT_00459858;
extern "C" char sub_000BE6C0[];

void __cdecl sub_002E3700(void)
{
    DAT_00459858.sub_00065550(0, (int)DAT_003FF908, (int)sub_000BE6C0, 0, 1, 1);
}
