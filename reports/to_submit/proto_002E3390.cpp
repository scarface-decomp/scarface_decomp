// bin: proto
// va: 0x002E3390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3390 (Proto 0x002E3390, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D30(int, int, int);
};

extern "C" Object DAT_00458E05;
extern "C" char sub_0009EF30[];

void __cdecl sub_002E3390(void)
{
    DAT_00458E05.sub_000D8D30(36, (int)sub_0009EF30, 0);
}
