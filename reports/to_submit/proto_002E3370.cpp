// bin: proto
// va: 0x002E3370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3370 (Proto 0x002E3370, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8D10(int, int, int);
};

extern "C" Object DAT_00458E04;
extern "C" char sub_0009F6F0[];

void __cdecl sub_002E3370(void)
{
    DAT_00458E04.sub_000D8D10(16, (int)sub_0009F6F0, 0);
}
