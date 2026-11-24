// bin: proto
// va: 0x002E61D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E61D0 (Proto 0x002E61D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B178[];
extern "C" char DAT_0040B190[];
extern "C" Object DAT_0045D120;
extern "C" char sub_00158140[];

void __cdecl sub_002E61D0(void)
{
    DAT_0045D120.sub_000655A0((int)DAT_0040B190, (int)DAT_0040B178, (int)sub_00158140, 0, 2, 2);
}
