// bin: proto
// va: 0x002E1670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1670 (Proto 0x002E1670, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F8A50[];
extern "C" Object DAT_0044A668;
extern "C" char sub_00055CD0[];

void __cdecl sub_002E1670(void)
{
    DAT_0044A668.sub_000655A0(0, (int)DAT_003F8A50, (int)sub_00055CD0, 0, 1, 2);
}
