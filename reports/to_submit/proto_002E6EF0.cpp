// bin: proto
// va: 0x002E6EF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6EF0 (Proto 0x002E6EF0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_0045DE64;
extern "C" char sub_001625B0[];

void __cdecl sub_002E6EF0(void)
{
    DAT_0045DE64.sub_000D8D10(37, (int)sub_001625B0, 0);
}
