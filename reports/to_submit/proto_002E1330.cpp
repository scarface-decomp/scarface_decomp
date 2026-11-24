// bin: proto
// va: 0x002E1330
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1330 (Proto 0x002E1330, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F7604[];
extern "C" Object DAT_0044A158;
extern "C" char sub_00039300[];

void __cdecl sub_002E1330(void)
{
    DAT_0044A158.sub_000655A0(0, (int)DAT_003F7604, (int)sub_00039300, 0, 1, 1);
}
