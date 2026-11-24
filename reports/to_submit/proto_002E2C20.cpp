// bin: proto
// va: 0x002E2C20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2C20 (Proto 0x002E2C20, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D30(int, int, int);
};

extern "C" Object DAT_004539DD;
extern "C" char sub_0007DBC0[];

void __cdecl sub_002E2C20(void)
{
    DAT_004539DD.sub_000D8D30(35, (int)sub_0007DBC0, 0);
}
