// bin: proto
// va: 0x002E4590
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4590 (Proto 0x002E4590, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00402304[];
extern "C" Object DAT_0045B4D0;
extern "C" char sub_000D8F70[];

void __cdecl sub_002E4590(void)
{
    DAT_0045B4D0.sub_00065550(0, (int)DAT_00402304, (int)sub_000D8F70, 0, 2, 2);
}
