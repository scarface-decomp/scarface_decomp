// bin: proto
// va: 0x002E9680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9680 (Proto 0x002E9680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004159BC[];
extern "C" Object DAT_00460BA0;
extern "C" char sub_001AC830[];

void __cdecl sub_002E9680(void)
{
    DAT_00460BA0.sub_000655A0(0, (int)DAT_004159BC, (int)sub_001AC830, 0, 3, 3);
}
