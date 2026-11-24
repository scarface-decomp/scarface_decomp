// bin: proto
// va: 0x002E3ED0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3ED0 (Proto 0x002E3ED0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FFAA8[];
extern "C" Object DAT_00459D0C;
extern "C" char sub_000C7B20[];

void __cdecl sub_002E3ED0(void)
{
    DAT_00459D0C.sub_00065550(0, (int)DAT_003FFAA8, (int)sub_000C7B20, 0, 3, 3);
}
