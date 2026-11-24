// bin: proto
// va: 0x002EC270
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC270 (Proto 0x002EC270, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00427494[];
extern "C" Object DAT_00462BC4;
extern "C" char sub_001E5AB0[];

void __cdecl sub_002EC270(void)
{
    DAT_00462BC4.sub_000655A0(0, (int)DAT_00427494, (int)sub_001E5AB0, 0, 5, 5);
}
