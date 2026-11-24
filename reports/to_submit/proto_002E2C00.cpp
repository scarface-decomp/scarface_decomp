// bin: proto
// va: 0x002E2C00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2C00 (Proto 0x002E2C00, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_004539DC;
extern "C" char sub_0007DB60[];

void __cdecl sub_002E2C00(void)
{
    DAT_004539DC.sub_000D8D10(17, (int)sub_0007DB60, 0);
}
