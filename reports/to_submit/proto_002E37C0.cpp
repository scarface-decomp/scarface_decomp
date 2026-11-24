// bin: proto
// va: 0x002E37C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E37C0 (Proto 0x002E37C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_004599CC;
extern "C" char sub_000BEA00[];

void __cdecl sub_002E37C0(void)
{
    DAT_004599CC.sub_000D8D10(33, (int)sub_000BEA00, 0);
}
