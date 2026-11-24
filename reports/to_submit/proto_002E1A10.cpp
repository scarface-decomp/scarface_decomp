// bin: proto
// va: 0x002E1A10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1A10 (Proto 0x002E1A10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9618[];
extern "C" Object DAT_0044B5F0;
extern "C" char sub_0005E5C0[];

void __cdecl sub_002E1A10(void)
{
    DAT_0044B5F0.sub_000655A0(0, (int)DAT_003F9618, (int)sub_0005E5C0, 0, 3, 4);
}
