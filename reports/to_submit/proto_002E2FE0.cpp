// bin: proto
// va: 0x002E2FE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2FE0 (Proto 0x002E2FE0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00383894[];
extern "C" Object DAT_00453F3C;
extern "C" char sub_000864E0[];

void __cdecl sub_002E2FE0(void)
{
    DAT_00453F3C.sub_000D8CC0(35, 3, 12, 61, 17, (int)DAT_00383894, (int)sub_000864E0, 248, 0, 1);
}
