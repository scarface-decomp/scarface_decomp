// bin: proto
// va: 0x002EC7C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC7C0 (Proto 0x002EC7C0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AB334[];
extern "C" Object DAT_00462ED4;
extern "C" char sub_001EB570[];

void __cdecl sub_002EC7C0(void)
{
    DAT_00462ED4.sub_000D8CC0(46, 33, 18, 30, 18, (int)DAT_003AB334, (int)sub_001EB570, 80, 0, 0);
}
