// bin: proto
// va: 0x002E6F10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6F10 (Proto 0x002E6F10, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D30(int, int, int);
};

extern "C" Object DAT_0045DE65;
extern "C" char sub_001B7A10[];

void __cdecl sub_002E6F10(void)
{
    DAT_0045DE65.sub_000D8D30(15, (int)sub_001B7A10, 0);
}
