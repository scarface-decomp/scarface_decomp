// bin: proto
// va: 0x002DFA10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFA10 (Proto 0x002DFA10, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_0043D884;
extern "C" char sub_00011500[];

void __cdecl sub_002DFA10(void)
{
    DAT_0043D884.sub_000D8D10(8, (int)sub_00011500, 0);
}
