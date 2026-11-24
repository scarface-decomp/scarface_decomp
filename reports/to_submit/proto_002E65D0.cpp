// bin: proto
// va: 0x002E65D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E65D0 (Proto 0x002E65D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B5D8[];
extern "C" char DAT_0040B5E8[];
extern "C" Object DAT_0045D6A0;
extern "C" char sub_00158D40[];

void __cdecl sub_002E65D0(void)
{
    DAT_0045D6A0.sub_000655A0((int)DAT_0040B5E8, (int)DAT_0040B5D8, (int)sub_00158D40, 0, 6, 6);
}
