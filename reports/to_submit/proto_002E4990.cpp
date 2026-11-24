// bin: proto
// va: 0x002E4990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4990 (Proto 0x002E4990, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0038B264[];
extern "C" Object DAT_0045BC7C;
extern "C" char sub_000F9A20[];

void __cdecl sub_002E4990(void)
{
    DAT_0045BC7C.sub_000D8CC0(40, 28, 24, 65, 11, (int)DAT_0038B264, (int)sub_000F9A20, 64, 0, 0);
}
