// bin: proto
// va: 0x002EC990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC990 (Proto 0x002EC990, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AB814[];
extern "C" Object DAT_00462F78;
extern "C" char sub_001ECAC0[];

void __cdecl sub_002EC990(void)
{
    DAT_00462F78.sub_000D8CC0(53, 38, 5, 83, 49, (int)DAT_003AB814, (int)sub_001ECAC0, 128, 0, 1);
}
