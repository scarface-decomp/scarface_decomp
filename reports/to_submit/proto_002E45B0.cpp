// bin: proto
// va: 0x002E45B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E45B0 (Proto 0x002E45B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003882D0[];
extern "C" Object DAT_0045B500;
extern "C" char sub_000D9210[];

void __cdecl sub_002E45B0(void)
{
    DAT_0045B500.sub_000D8CC0(48, 43, 34, 89, 53, (int)DAT_003882D0, (int)sub_000D9210, 509, 3, 1);
}
