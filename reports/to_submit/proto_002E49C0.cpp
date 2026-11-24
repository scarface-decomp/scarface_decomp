// bin: proto
// va: 0x002E49C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E49C0 (Proto 0x002E49C0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0038B298[];
extern "C" Object DAT_0045BC84;
extern "C" char sub_000FA9D0[];

void __cdecl sub_002E49C0(void)
{
    DAT_0045BC84.sub_000D8CC0(43, 30, 17, 67, 13, (int)DAT_0038B298, (int)sub_000FA9D0, 64, 0, 0);
}
