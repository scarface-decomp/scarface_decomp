// bin: proto
// va: 0x002E3740
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3740 (Proto 0x002E3740, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF924[];
extern "C" Object DAT_004598B0;
extern "C" char sub_000BE9C0[];

void __cdecl sub_002E3740(void)
{
    DAT_004598B0.sub_00065550(0, (int)DAT_003FF924, (int)sub_000BE9C0, 0, 2, 2);
}
