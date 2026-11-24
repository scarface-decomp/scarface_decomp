// bin: proto
// va: 0x002E37E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E37E0 (Proto 0x002E37E0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D30(int, int, int);
};

extern "C" Object DAT_004599CD;
extern "C" char sub_000BEAA0[];

void __cdecl sub_002E37E0(void)
{
    DAT_004599CD.sub_000D8D30(20, (int)sub_000BEAA0, 0);
}
