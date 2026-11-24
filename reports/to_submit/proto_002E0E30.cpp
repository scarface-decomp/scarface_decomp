// bin: proto
// va: 0x002E0E30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0E30 (Proto 0x002E0E30, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_00449AE5;
extern "C" char sub_0002BD10[];

void __cdecl sub_002E0E30(void)
{
    DAT_00449AE5.sub_000D8D10(1, (int)sub_0002BD10, 0);
}
